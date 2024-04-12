#pragma once

#include <string>
#include <vector>

class ExpansionTree {
public:
    std::string string;
    ExpansionTree *father;
    std::vector<ExpansionTree*> *next_node;

    ExpansionTree(std::string str, ExpansionTree *ftr);
    ~ExpansionTree();

    void push_nodes(std::vector<ExpansionTree*> *nodes);
};