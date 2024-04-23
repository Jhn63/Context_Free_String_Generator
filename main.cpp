#include "FileHandler.hpp"

int main(int argc, char* argv[]) {
    FileHandler handler;
    Generator *gen = handler.read(argv[1]);
    
    char input = '1';
    while (input) {
        std::cout << std::endl;
        std::cout << "Gerador de Cadeias para Gramaticas Livre de Contexto" << std::endl;
        std::cout << "[1] modo rapido      [2] modo detalhado     [0] sair" << std::endl;
        std::cout << ">> ";
        std::cin >> input;

        switch (input) {
            case '1': {
                int qtt;
                std::cout << std::endl << "Quantidade de cadeias a serem geradas\n";
                std::cout << ">> ";
                std::cin >> qtt;
                std::cout << std::endl << std::endl;
                gen->fast_mode(qtt);
                break;    
            }
            case '2': {
                std::cout << std::endl;
                gen->detail_mode();
                break;
            }
            case '0': {
                std::cout << "\nDesligando..." << std::endl;
                input = 0;
                break;
            }
            default: {
                std::cout << "\n\nENTRADA INVALIDA\n" << std::endl;
                break;
            }
        }
    }
    delete gen;
}