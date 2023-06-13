#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include "mergeSort.cpp"


// Before we extended TestCase() class now we extend the textFixture class which has more features

class mergeSortTests : public CppUnit::TestFixture 
{
    public: 
        void testMerge() {
           int size = 6;
           int* arr = new int[size] {400, 500, 600, 112, 248, 345};
           int* helper = new int[size];
           int low = 0;
           int high = size - 1;
           int mid = low + floor((high - low)/2);;
           std::cout << "Hi" << std::endl;
           printArray(arr, size); 
           merge(arr, size, helper, low, mid, high);
           printArray(arr, size);
           CPPUNIT_ASSERT(arr[0] == 112);
           CPPUNIT_ASSERT(arr[1] == 248);
           CPPUNIT_ASSERT(arr[2] == 345);
           CPPUNIT_ASSERT(arr[3] == 400);
           CPPUNIT_ASSERT(arr[4] == 500);
           CPPUNIT_ASSERT(arr[5] == 600);
        }
        void testMergeSort() {
           int size = 6;
           int* arr = new int[size] {100, 45, 20, 24, -1, -87};
           mergeSort(arr, size);
           printArray(arr, size); 
           CPPUNIT_ASSERT(arr[0] == -87);
           CPPUNIT_ASSERT(arr[1] == -1);
           CPPUNIT_ASSERT(arr[2] == 20);
           CPPUNIT_ASSERT(arr[3] == 24);
           CPPUNIT_ASSERT(arr[4] == 45);
           CPPUNIT_ASSERT(arr[5] == 100);
        }
      


        /*
        //Empty array
        void testEmptyArray() {
            int size = 0;
            int* testmergeSort = new int[size];
            mergeSort(testmergeSort, size);
            int* expected = new int[size];
            CPPUNIT_ASSERT(testmergeSort == expected);
        }

        // Array of one element
        void testOneElement() {
            int size = 1;
            int* testmergeSort = new int[size] {50};
            mergeSort(testmergeSort, size);
            int* expected = new int[size] {50};
            CPPUNIT_ASSERT(testmergeSort == expected);
        }

        // Array of all equal elements
        void testAllEqualElements() {
            int size = 5;
            int* testmergeSort = new int[size] {1, 1, 1, 1, 1};
            int* resultBubble = mergeSort(testmergeSort, size);
            int* expected = new int[size] {50};
            CPPUNIT_ASSERT(testmergeSort == expected);
        }

        // Array of all reversed elements
        void testreversedOrderList() {
            int size = 5;
            int* testmergeSort = new int[size] {5, 4, 3, 2, 1};
            int* resultBubble = mergeSort(testmergeSort, size);
            CPPUNIT_ASSERT_EQUAL(1, testmergeSort[0]);
            CPPUNIT_ASSERT_EQUAL(2, testmergeSort[1]);
            CPPUNIT_ASSERT_EQUAL(3, testmergeSort[2]);
            CPPUNIT_ASSERT_EQUAL(4, testmergeSort[3]);
            CPPUNIT_ASSERT(testmergeSort == expected);
        }

        // Array with duplicates
        void testDuplicates() {
            int size = 5;
            int* testmergeSort = new int[size] {5, 4, 4, 2, 1};
            int* resultBubble = mergeSort(testmergeSort, size);
            CPPUNIT_ASSERT_EQUAL(1, testmergeSort[0]);
            CPPUNIT_ASSERT_EQUAL(2, testmergeSort[1]);
            CPPUNIT_ASSERT_EQUAL(4, testmergeSort[2]);
            CPPUNIT_ASSERT_EQUAL(4, testmergeSort[3]);
            CPPUNIT_ASSERT_EQUAL(5, testmergeSort[4]);
        }

        // Array with duplicates
        void testNegativeNumbers() {
            int size = 5;
            int* testmergeSort = new int[size] {5, -3, 4, 2, 1};
            int* resultBubble = mergeSort(testmergeSort, size);
            CPPUNIT_ASSERT_EQUAL(-3, testmergeSort[0]);
            CPPUNIT_ASSERT_EQUAL(1, testmergeSort[1]);
            CPPUNIT_ASSERT_EQUAL(2, testmergeSort[2]);
            CPPUNIT_ASSERT_EQUAL(4, testmergeSort[3]);
            CPPUNIT_ASSERT_EQUAL(5, testmergeSort[4]);
        }
        */


};