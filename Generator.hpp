#pragma once

#include <queue>
#include <cctype>
#include <iostream>
#include <unordered_set>

#include "ExpansionTree.hpp"

class Generator {
private:
    ExpansionTree *root;
    
    std::vector<std::pair<char, std::string>> productions;
    std::unordered_set<std::string> tracker;
    std::queue<ExpansionTree*> queue_deriv;

    bool already_exists(std::string &str);
    std::string back_tracking(ExpansionTree &node);
    std::vector<ExpansionTree*> *expand_node(ExpansionTree &node); 

public:
    Generator(const std::vector<std::pair<char, std::string>> &prod_list);
    ~Generator();

    void fast_mode(const int iter);
};