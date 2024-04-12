#include "Generator.hpp"

int main() {

    Generator gen({{'S',"0S1",},{'S',"SS"},{'S',""}});
    gen.fast_mode(10);
    
    std::cout << "second loop" << std::endl;
    gen.fast_mode(10);
}