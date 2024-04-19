#include "FileHandler.hpp"

int main(int argc, char* argv[]) {
    FileHandler handler;
    Generator *gen = handler.read(argv[1]);
    
    char input = '1';
    while (input) {
        std::cout << std::endl;
        std::cout << "Gerador de Cadeias Livre de Contexto" << std::endl;
        std::cout << "[1] modo rapido   [2] modo detalhado" << std::endl;
        std::cin >> input;

        switch (input) {
            case '1': {
                int qtt;
                std::cout << std::endl << "Quantidade de cadeias a serem geradas: ";
                std::cin >> qtt;
                std::cout << std::endl;
                gen->fast_mode(qtt);
                break;    
            }
            case '2': {
                std::cout << std::endl << "Nao implementado" << std::endl << std::endl;
                break;
            }
            default: {
                input = 0;
                break;
            }
        }
    }
    delete gen;
}