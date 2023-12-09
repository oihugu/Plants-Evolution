#include <string>
#include <vector>

#include "include/Rule.hpp"

using namespace std;

Rule::Rule(char c) {
    this->start = c;
}

void Rule::setInitChar(char c) {
    this->start = c;
}

void Rule::setReplacement(string s) {
    this->replacement = s;
}

char Rule::getInitChar(){
    return start;
}

string Rule::getReplacement(){
    return replacement;
}


TTTest::TTTest(){
    this->test_string = "test";
}
