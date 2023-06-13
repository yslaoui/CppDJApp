#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include "bubbleSort.cpp"


// Before we extended TestCase() class now we extend the textFixture class which has more features

class bubbleSortTests : public CppUnit::TestFixture 
{
    public: 
        void testSwap() 
        {
            int size = 5;
            int* testSwap = new int[size] {1, 2, 3, 4, 5};
            int* resultSwap = swap(testSwap, 0, 1);
            CPPUNIT_ASSERT(testSwap[0] == 2);
            CPPUNIT_ASSERT(testSwap[1] == 1);
        }

        void testBubbleSort() {
            int size = 5;
            int* testBubbleSort = new int[size] {78, 54 , 89, 98, 2};
            int* resultBubble = bubbleSort(testBubbleSort, size);
            CPPUNIT_ASSERT_EQUAL(2, testBubbleSort[0]);
            CPPUNIT_ASSERT_EQUAL(54, testBubbleSort[1]);
            CPPUNIT_ASSERT_EQUAL(89, testBubbleSort[2]);
            CPPUNIT_ASSERT_EQUAL(98, testBubbleSort[3]);
            CPPUNIT_ASSERT_EQUAL(78, testBubbleSort[4]);
          }
        //Empty array
        void testEmptyArray() {
            int size = 0;
            int* testBubbleSort = new int[size];
            int* resultBubble = bubbleSort(testBubbleSort, size);
            CPPUNIT_ASSERT(resultBubble == testBubbleSort);
        }

        // Array of one element
        void testOneElement() {
            int size = 1;
            int* testBubbleSort = new int[size] {50};
            int* resultBubble = bubbleSort(testBubbleSort, size);
            CPPUNIT_ASSERT(resultBubble == testBubbleSort);
        }

        // Array of all equal elements
        void testAllEqualElements() {
            int size = 5;
            int* testBubbleSort = new int[size] {1, 1, 1, 1, 1};
            int* resultBubble = bubbleSort(testBubbleSort, size);
            CPPUNIT_ASSERT(resultBubble == testBubbleSort);
        }

        // Array of all reversed elements
        void testreversedOrderList() {
            int size = 5;
            int* testBubbleSort = new int[size] {5, 4, 3, 2, 1};
            int* resultBubble = bubbleSort(testBubbleSort, size);
            CPPUNIT_ASSERT_EQUAL(1, testBubbleSort[0]);
            CPPUNIT_ASSERT_EQUAL(2, testBubbleSort[1]);
            CPPUNIT_ASSERT_EQUAL(3, testBubbleSort[2]);
            CPPUNIT_ASSERT_EQUAL(4, testBubbleSort[3]);
            CPPUNIT_ASSERT_EQUAL(5, testBubbleSort[4]);
        }

        // Array with duplicates
        void testDuplicates() {
            int size = 5;
            int* testBubbleSort = new int[size] {5, 4, 4, 2, 1};
            int* resultBubble = bubbleSort(testBubbleSort, size);
            CPPUNIT_ASSERT_EQUAL(1, testBubbleSort[0]);
            CPPUNIT_ASSERT_EQUAL(2, testBubbleSort[1]);
            CPPUNIT_ASSERT_EQUAL(4, testBubbleSort[2]);
            CPPUNIT_ASSERT_EQUAL(4, testBubbleSort[3]);
            CPPUNIT_ASSERT_EQUAL(5, testBubbleSort[4]);
        }

        // Array with duplicates
        void testNegativeNumbers() {
            int size = 5;
            int* testBubbleSort = new int[size] {5, -3, 4, 2, 1};
            int* resultBubble = bubbleSort(testBubbleSort, size);
            CPPUNIT_ASSERT_EQUAL(-3, testBubbleSort[0]);
            CPPUNIT_ASSERT_EQUAL(1, testBubbleSort[1]);
            CPPUNIT_ASSERT_EQUAL(2, testBubbleSort[2]);
            CPPUNIT_ASSERT_EQUAL(4, testBubbleSort[3]);
            CPPUNIT_ASSERT_EQUAL(5, testBubbleSort[4]);
        }


};