#include <string>
#include <vector>
#include "include/LSystem.hpp"

using namespace std;


LSystem::LSystem(vector<char> V,
        string W,
        vector<Rule> P){
    // G(V,W,P)
    // V is a list of Variables
    // W is the axiom
    // P is the set of Production rules
    this->aplhabet = V;
    this->axiom = W;
    this->production_rules = P;
    this->actual_state = W;
}


void LSystem::applyRules(){
    for (auto it =  this->production_rules.begin();
                it != this->production_rules.end();
                ++it){
        Rule& rule = *it;
        rule.replace(this->actual_state);
    }
}

string LSystem::getState(){
    return this->actual_state;
}