#include "gtest/gtest.h"
#include <string>
#include "factory.hpp"
#include "op.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(FactoryAddTest, AddAdd){
char* testInput[2];
std::string str = "1+5+9";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), 15);
}

TEST(FactoryAddTest, AddSub){
char* testInput[2];
std::string str = "1+5-9";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), -3);
}

TEST(FactoryAddTest, AddMult){
char* testInput[2];
std::string str = "5+7*10";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), 120);
}

TEST(FactoryAddTest, AddDiv){
char* testInput[2];
std::string str = "35+20/5";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), 11);
}

TEST(FactoryAddTest, SubAdd){
char* testInput[2];
std::string str = "10-50+30";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), -10);
}

TEST(FactoryAddTest, SubSub){
char* testInput[2];
std::string str = "10-50-30";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), -70);
}

TEST(FactoryAddTest, SubMult){
char* testInput[2];
std::string str = "5-7*8";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), -16);
}

TEST(FactoryAddTest, SubDiv){
char* testInput[2];
std::string str = "35-20/-5";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), -3);
}

TEST(FactoryAddTest, MultAdd){
char* testInput[2];
std::string str = "1*5+9";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), 14);
}

TEST(FactoryAddTest, MultSub){
char* testInput[2];
std::string str = "5*7+10";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), 45);
}

TEST(FactoryAddTest, MultMult){
char* testInput[2];
std::string str = "3*2*5";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), 30);
}

TEST(FactoryAddTest, MultDiv){
char* testInput[2];
std::string str = "3*20/5";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), 12);
}

TEST(FactoryAddTest, DivAdd){
char* testInput[2];
std::string str = "24/6*-9";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), -36);
}

TEST(FactoryAddTest, DivSub){
char* testInput[2];
std::string str = "35/7-10";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), -5);
}

TEST(FactoryAddTest, DivMult){
char* testInput[2];
std::string str = "100/20*5";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), 25);
}

TEST(FactoryAddTest, DivDiv){
char* testInput[2];
std::string str = "100/20/5";
testInput[1] = const_cast <char*> (str.c_str());
Factory* f = new Factory();
//Op* op = f->parse(testInput,1);
EXPECT_EQ((f->parse(testInput,1))->evaluate(), 1);
}
