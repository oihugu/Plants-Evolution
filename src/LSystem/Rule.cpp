#include <string>
#include <vector>

#include "include/Rule.hpp"

using namespace std;

Rule::Rule(char c, string s) {
    this->start = c;
    this->replacement = s;
}

void Rule::setInitChar(char c) {
    this->start = c;
}

void Rule::setReplacement(string s) {
    this->replacement = s;
}

char Rule::getInitChar(){
    return this->start;
}

string Rule::getReplacement(){
    return this->replacement;
}

