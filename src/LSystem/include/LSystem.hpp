#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <string>
#include <vector>
#include "Rule.hpp"

class LSystem {
private:
    string axiom;
    string actual_state;
    vector<char> aplhabet;
    vector<Rule> production_rules;
    
    string replace(string state, Rule rule);
public:
    LSystem(vector<char> V, string W, vector<Rule> P);

    void applyRules(vector<Rule> Rules);
    string getState();
};

#endif