#include <string>
#include <vector>
#include "include/Rule.hpp"

using namespace std;

class LSystem {
private:
    string axiom;
    string actual_state;
    vector<char> aplhabet;
    vector<Rule> production_rules;

public:
    LSystem(vector<char> V,
            string W,
            vector<Rule> P){
        // G(V,W,P)
        // V is a list of Variables
        // W is the axiom
        // P is the set of Production rules
        aplhabet = V;
        axiom = W;
        production_rules = P;
        actual_state = W;
    }

    string replace(string state, Rule rule){
        string new_str;
        for (int i; i < state.size(); i++){
            if (state[i] == rule.getInitChar())
                new_str.append(rule.getReplacement());
            else
                new_str.append(&state[i]);
        }
        return new_str;
    }

    void applyRules(vector<Rule> Rules){
        for (auto it =  Rules.begin();
                  it != Rules.end();
                  ++it){
            Rule& rule = *it;
            this->actual_state = this->replace(actual_state, rule);
        }
    }

    string getState(){
        return this->actual_state;
    }
};