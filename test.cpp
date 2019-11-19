#include "gtest/gtest.h"
#include <string>
#include "factory.hpp"
#include "op.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(FactoryAddTest, AddFirst){
char* testInput[2];
std::string str = "1+5-9";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), -3.00000);
}

TEST(FactoryAddTest, AddMid){

}

TEST(FactoryAddTest, AddEnd){

}
