#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include "Generator.hpp"

class FileHandler {
private:
    void process_line1(std::string &line);
    void process_line2(std::string &line);
    void process_line3(std::string &line);
    std::vector<std::pair<char, std::string>>* process_grammar(std::ifstream &stream);

    void assert(bool condition, std::string msg);
    std::vector<std::string>* tokenize(std::string &str, char delimiter);
public:
    
    Generator* read(char *path);
};