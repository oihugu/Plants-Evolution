#include <gtest/gtest.h>
#include "LSystem/include/LSystem.hpp"
#include "LSystem/include/Rule.hpp"

#include "Display/include/Display.hpp"

using namespace sf;

int main(int argc, char *argv[]){

    if (argc >= 2){
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

    Display display;


    
}