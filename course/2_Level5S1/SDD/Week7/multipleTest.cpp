/*
in the output . means passed and F means failed
.F means one test passed and the other failed
*/


#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include "bubbleSort.cpp"



// Before we extended TestCase() class now we extend the textFixture class which has more features

class myTests : public CppUnit::TestFixture 
{
    public: 

        void setUp() override 
        {
            printf("setup is called \n");
        }

        void tearDown() override 
        {
            printf("teardown is called \n");
        }

        void testAddition() 
        {
            CPPUNIT_ASSERT(2+2 == 3);
            CPPUNIT_ASSERT(2+2 == 4);
        }
        void testLogic() 
        {
            CPPUNIT_ASSERT(true == false);
            CPPUNIT_ASSERT(false == false);
        }

        void testSwap() 
        {
            int size = 5;
            int* testSwap = new int[size] {1, 2, 3, 4, 5};
            int* resultSwap = swap(testSwap, 0, 1);
            CPPUNIT_ASSERT(testSwap[0] == 2);
            CPPUNIT_ASSERT(testSwap[1] == 1);
        }


};

int main() 
{
    // Create a test runner that will run test for me
    CppUnit::TextUi::TestRunner myrunner{};
    // Add test to test runner
    myrunner.addTest(new CppUnit::TestCaller<myTests> {
        "test the addition operator", 
        &myTests::testAddition // basic test function wrapped in a test caller
    });

    myrunner.addTest(new CppUnit::TestCaller<myTests> {
    "test the logic operator", 
    &myTests::testLogic // basic test function wrapped in a test caller
    });


    myrunner.addTest(new CppUnit::TestCaller<myTests> {
    "test the swap function", 
    &myTests::testSwap // basic test function wrapped in a test caller
    });

    myrunner.run();

}




