#include <string>
#include <vector>

using namespace std;

class Rule {

    char start;
    string replacement;

    Rule(char s,
        string r) {
        // s start char
        // r replacement string
        start = s;
        replacement = r;
    }
};

class LSystem {
    vector<char> aplhabet;
    string axiom;
    string actual_state;
    vector<Rule> production_rules;

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

    // void applyRules(vector<Rule> Rules){
    //     for (auto rule =  Rules.begin();
    //               rule != Rules.end();
    //               ++rule){
    //         actual_state.replace()
    //     }
    // }
};