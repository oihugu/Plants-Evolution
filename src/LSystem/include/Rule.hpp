#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>

using namespace std;

class Rule{
private:
    char start;
    string replacement;
public:
    Rule();
    Rule(char c);
    // Setters
    void setInitChar(char c);
    void setReplacement(string s);
    // Getters
    char getInitChar();
    string getReplacement();
};

class Test{
private:
    string test_string;
public:
    Test();
};

#endif