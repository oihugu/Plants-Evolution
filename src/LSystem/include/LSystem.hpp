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
public:
    // Constructor
    LSystem(vector<char> V, string W, vector<Rule> P);
    // Methods
    void applyRules();
    // Getters
    string getState();
    // Setters
};

#endif