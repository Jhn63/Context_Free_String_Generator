#include "ExpansionTree.hpp"

/*Cada nodulo é instanciado sem filhos*/
ExpansionTree::ExpansionTree(std::string str, ExpansionTree *ftr) : string(str), father(ftr), next_node(nullptr) {}

/* Ao deletar um nó, recursivamente todos demais nós
** "abaixo dele" são deletados. Porem vale ressaltar que o seu
** nó pai ainda pode manter referencia a posição de memoria dele */
ExpansionTree::~ExpansionTree() {
    if (next_node != nullptr) {
        for (auto node : *next_node) {
            delete node;
        }
        delete next_node;
    }
}

/*Recebe ferencia para os filhos da arvore*/
void ExpansionTree::push_nodes(std::vector<ExpansionTree*> *nodes) {
    next_node = nodes;
}