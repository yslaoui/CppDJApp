/*
Install cppunit
sudo apt-get update
sudo apt-get install libcppunit-dev

run this code
g++ basicTest.cpp -lcppunit
./a.out
*/


#include <iostream>
#include <cppunit/TestCase.h>

 //e BasicTest class is inheriting from the TestCase class and it extends it to include our own tests as methods


 class BasicTest : public CppUnit::TestCase 
 {
    public:
        // our class inherits the constructor from the TestCase class
        BasicTest(std::string name) : CppUnit::TestCase(name) {}
        // It overrides the vurtual method runTest() of the TestCase class
        void runTest() override 
        {
            CPPUNIT_ASSERT(2 + 2 == 4);
            // CPPUNIT_ASSERT(2 + 2 == 3);

        }
 };

 int main() 
 {
    BasicTest test{"BasicTest"};
    test.runTest();
 }