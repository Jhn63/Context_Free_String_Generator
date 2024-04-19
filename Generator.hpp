#pragma once

#include <queue>
#include <cctype>
#include <iostream>
#include <unordered_set>

#include "ExpansionTree.hpp"

class Generator {
private:
    ExpansionTree *root;
    std::queue<ExpansionTree*> queue_deriv;
    std::vector<std::pair<char, std::string>> *productions;

    std::string back_tracking(ExpansionTree &node);
    std::vector<ExpansionTree*> *expand_node(ExpansionTree &node); 

public:
    Generator(std::vector<std::pair<char, std::string>> *prod_list);
    ~Generator();

    void fast_mode(const int iter);
};