#include <string>
#include <vector>

#include "include/Rule.hpp"

using namespace std;

Rule::Rule(char c, string s) {
    this->start = c;
    this->replacement = s;
}

void Rule::replace(string& str) {
    string from;
    from.push_back(this->start);
    size_t start_pos = str.find(from);
    str.replace(start_pos, from.length(), this->replacement);
}

// Setters
void Rule::setInitChar(char c) {
    this->start = c;
}

void Rule::setReplacement(string s) {
    this->replacement = s;
}

// Getters
char Rule::getInitChar(){
    return this->start;
}

string Rule::getReplacement(){
    return this->replacement;
}

