#include "FileHandler.hpp"

Generator* FileHandler::read(char *path) {
    std::ifstream input;
    std::string line;

    input.open(path);
    assert(!input.is_open(), "Arquivo nao encontrado");
    
    std::getline(input, line);
    process_line1(line);

    std::getline(input, line);
    process_line2(line);

    std::getline(input, line);
    process_line3(line);

    std::getline(input, line); //pulando uma linha
    auto productions = process_grammar(input);

    input.close();
    return new Generator(productions);
}

/*Verifica se as variaveis estão em maiusculo*/
void FileHandler::process_line1(std::string &line) {
    std::string trash = "variaveis:";
    size_t pos = line.find(trash);
    assert(pos != 0, "Formato do arquivo nao suportavel");
    
    line.erase(pos,trash.length());
    auto tokens = tokenize(line, ',');
    for (auto t : *tokens) {   
        assert(t.length() > 1, "Variavel nao permitida: " + t);

        const char *c = t.c_str();
        assert(!isupper(*c), "Variavel em minusculo nao eh permitida: " + t);
    }
    delete tokens;
}

/*Verifica se a variavel inicial é S*/
void FileHandler::process_line2(std::string &line) {
    std::string trash = "inicial:";
    size_t pos = line.find(trash);
    assert(pos != 0, "Formato do arquivo nao suportavel");

    line.erase(pos,trash.length());
    assert(line != "S", "Variavel inicial precisa ser S");
}

/*verifica se os terminais são Não-maiusculos*/
void FileHandler::process_line3(std::string &line) {
    std::string trash = "terminais:";
    size_t pos = line.find(trash);
    assert(pos != 0, "Formato do arquivo nao suportavel");
    
    line.erase(pos,trash.length());
    auto tokens = tokenize(line, ',');
    for (auto t : *tokens) {   
        assert(t.length() > 1, "Simbolo Terminal nao permitido: " + t);

        const char *c = t.c_str();
        assert(isupper(*c), "Simbolo Terminal em maiusculo nao eh permitido: " + t);
    }
    delete tokens;
}

/*Converte as produções em um vetor de pares<variavel, produção>*/
std::vector<std::pair<char, std::string>>* FileHandler::process_grammar(std::ifstream &stream) {
    auto *productions = new std::vector<std::pair<char, std::string>>();

    std::string line;
    std::getline(stream,line);
    assert(line != "producoes", "Formato do arquivo nao suportado");

    while(std::getline(stream,line)) {
        auto *tokens = tokenize(line, ':');
        //falta verificação
        const char *right = (*tokens)[0].c_str();
        std::string left = (*tokens)[1].erase(0,1);
        if (left == "epsilon") left = "";

        productions->push_back({*right, left});
        delete tokens;
    }

    return productions;
}

/*Quebra uma string nos simbolos delimitados*/
std::vector<std::string>* FileHandler::tokenize(std::string &str, char delimiter) {
    auto tokens = new std::vector<std::string>();
    
    std::string token;
    std::istringstream iss(str);
    while (std::getline(iss, token, delimiter)) {
        tokens->push_back(token);
    }
    return tokens;
}

/*Imprime uma mensagem dada uma condição*/
void FileHandler::assert(bool condition, std::string msg) {
    if (condition) {
        std::cerr << "ERRO: " << msg << std::endl;
        exit(-1);
    }
}