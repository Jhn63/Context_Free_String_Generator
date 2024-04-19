#include "Generator.hpp"

/* As produções são representadas pelo par <char, string> representando o
** lado direito e esquerdo respectivamente, o objeto recebe um vector de produções
** com uma UNICA produção por posição no vetor */
Generator::Generator(std::vector<std::pair<char, std::string>> *prod_list) : productions(prod_list) {
    root = new ExpansionTree("S", nullptr);
    queue_deriv.push(root);
}

/* Deleta toda a árvore e esvazia
** a fila para não manter referências */
Generator::~Generator() {
    delete root;
    delete productions;
    while (!queue_deriv.empty()) {
        queue_deriv.pop();
    }
}

/* No modo rápido o usuário informa quantas cadeias ele quer produzir.
** A função utiliza uma fila para saber as cadeias que devem ser derivadas,
** ao chamar a função expand_node() se o retorno for um ponteiro nulo quer dizer
** que aquela cadeia não pode mais ser derivada, então a função back_tracking()
** mostra ao usuário o caminho que foi feito para chegar na derivação final.
** Por outro lado se a condicional if for aceita, um vetor com as possiveis derivações
** é criado e passado como "proximos nós" do nó atual */
void Generator::fast_mode(const int iter) { 

    for (int i = 0; i < iter && !queue_deriv.empty(); ) {
        ExpansionTree *current = queue_deriv.front();
        auto *nodes = expand_node(*current);
        
        if (nodes != nullptr) {

            for (auto it = nodes->begin(); it != nodes->end(); it++) {
                queue_deriv.push(*it);
            }
            current->push_nodes(nodes);
        }
        else {
            std::cout << back_tracking(*current) << std::endl << std::endl;
            i++;
        }
        
        queue_deriv.pop();
    }
}

/* Função para subir na árvore
** apartir do nó de entrada concatena todas as strings até a raiz*/
std::string Generator::back_tracking(ExpansionTree &node) {
    ExpansionTree *aux = &node;
    std::string concat = node.string;
    if (concat.empty()) concat = "epsilon";

    aux = aux->father;
    while (aux != nullptr) {
        concat = aux->string + " -> " + concat;
        aux = aux->father;
    }
    return concat;
}


/* Funçao para derivar o simbolo não-terminal mais a esquerda
** Primeiro verifica se existe algum simbolo não-terminal e seleciona
** aquele mais a esquerda. Se houver simbolo é retornado um vector com todas
** as possiveis derivações para aquele simbolo não-terminal, por outro lado
** se não houver simbolos não-terminais a função retorna um nullptr */
std::vector<ExpansionTree*> *Generator::expand_node(ExpansionTree &node) {
    char sym = 0;
    int index = 0;
    for (char c : node.string) {
        if (std::isupper(c)) {
            sym = c;
            break;
        }
        index++;
    }
    
    if (sym != 0) {
        auto *result = new std::vector<ExpansionTree*>();
        for (auto prod : *productions) {

            if (prod.first == sym) {

                std::string copy = node.string;
                copy.replace(index, 1, prod.second);

                ExpansionTree *e = new ExpansionTree(copy, &node);
                result->push_back(e);
            }
        }
        return result;
    }
    return nullptr;
}