// g++ main.cpp -lcppunit

#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include "./mergeSort_test.cpp"

int main() 
{
    
    // Create a test runner that will run test for me
    CppUnit::TextUi::TestRunner myrunner{};
    
    // Add test bubble Sort to test runner
    
    myrunner.addTest(new CppUnit::TestCaller<mergeSortTests> {
        "test the addition operator", 
        &mergeSortTests::testMerge // basic test function wrapped in a test caller
    });
    

    // Add test bubble Sort to test runner
    myrunner.addTest(new CppUnit::TestCaller<mergeSortTests> {
        "test the addition operator", 
        &mergeSortTests::testMergeSort // basic test function wrapped in a test caller
    });
   
    myrunner.run();
}