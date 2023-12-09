#include <iostream>
#include <string>
#include <vector>

#include "../src/LSystem/include/LSystem.hpp"
#include "../src/LSystem/include/Rule.hpp"

#include <gtest/gtest.h>



// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

//////////////////////////////////////////
// Rule Tests
//////////////////////////////////////////

TEST(Rule, Constructor) {
    Rule rule('A', "AB");
    EXPECT_EQ(rule.getInitChar(), 'A');
    EXPECT_EQ(rule.getReplacement(), "AB");
}

TEST(Rule, Setters) {
    Rule rule('A', "AB");
    rule.setInitChar('B');
    rule.setReplacement("BA");
    EXPECT_EQ(rule.getInitChar(), 'B');
    EXPECT_EQ(rule.getReplacement(), "BA");
}

TEST(Rules, Replace) {
    Rule rule('A', "AB");
    string str = "A";
    rule.replace(str);
    EXPECT_EQ(str, "AB");
}

//////////////////////////////////////////
// LSystem Tests
//////////////////////////////////////////

TEST(LSystem, Constructor) {
    LSystem lsystem(vector<char>{'A','B'},
            "A",
            vector<Rule>{Rule('A',"AB"), Rule('B',"BA")});

    EXPECT_EQ(lsystem.getState(), "A");
}

TEST(LSystem, ApplyRules) {
    LSystem lsystem(vector<char>{'A','B'},
            "A",
            vector<Rule>{Rule('A',"AB"), Rule('B',"BA")});

    lsystem.applyRules();

    EXPECT_EQ(lsystem.getState(), "ABA");
}

