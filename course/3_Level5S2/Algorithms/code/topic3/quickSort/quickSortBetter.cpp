 /* This is an inplace implementation of quickSort
 In this implementation of quickSort, we use a helper
 function called partition() that returns the pivot, and mofifies
 the array so that in the new array, the numbers < pivot are to the left of the pivot
 and the numbers > pivot are to the right of the pivot 
 In this implementation, we use (fixed size) arrays and not vectors
 In this implementation, the same array is tranformed at each step, onlyu indices changes
 Therefore this implementtation has better space complexity as the precedent where new vectors are created so the brute force is )(n)
The key here is that the code is in place. There are many subtleties here 
The quickSort() function returns void. But in the process it ransforms the argument array at each step 
The partition function returns the pivot and transforms the array in place. It does the heavy lifting
The code is actually beautiful. The bease case is implicit: if low==high yo do nothing. Because quicksort returns nothing
it changesthe input array and the result is still in that initial array 

 */

#include <iostream>
#include <cmath>

void printArray(int* arr, int size) 
{
    for (int i=0; i< size; ++i) 
    {
        std::cout << arr[i] << " ,";
    }
    std::cout << std::endl;
}

int* swap(int* arr, int i, int j) 
{
    int c = arr[i];
    arr[i] = arr[j];
    arr[j] = c;
    return arr;
}



int partition(int* arr, int low, int high) 
{
    std::cout << "Entering the partition function" << std::endl;
    int pivotIndex = floor((low+high)/2);
    int i = low;
    int j = high; 
    while( i < j) 
    {
        std::cout << "New outter while loop iteration" << std::endl;
        std::cout << "i is " << i << " and j is " << j << " and pivot is " << pivotIndex <<  std::endl;
        while ((arr[i] < arr[i+1]) && (i < pivotIndex) ) 
        {
            i++;
        }
        while ((arr[j] > arr[j-1] && (j > pivotIndex))) 
        {
            j--;
        }
        std::cout << "Proceeding to  swap indices " << i <<" and "<< j <<  std::endl;
        swap(arr, i, j);
        printArray(arr, 5);
    }
    std::cout << "reached end of the partition function" << std::endl;
    return pivotIndex;

}

void quickSort(int* arr, int low, int high) 
{
    std::cout << "recursive function call on the following array:  " << " with low = " << low << " and high = " << high << std::endl;
    printArray(arr, 5); 
    if (low < high) 
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
    std::cout << "Base case of quickSort reached" << std::endl;
    return;
    
}


int main() 
{
    // testing print
    int size = 5;
    int* testArray = new int[size] {100, 87, 1002, 58, 1005};
    std::cout << "testing the print method" << std::endl;
    printArray(testArray, size);

    // testing swap
    /*
    int* testSwap = swap(testArray, 0, 4);
    printArray(testSwap, size);
    std::cout << "testing the swap method" << std::endl;
    */
    
    // testing partition
    std::cout << "testing the partition method" << std::endl;
    int testPartition = partition(testArray, 0, size-1);
    printArray(testArray, size);    

    // // testing quickSort
    // quickSort(testArray, 0, size-1);
    // printArray(testArray, size);

}


/*
Time complexity
https://towardsdatascience.com/an-overview-of-quicksort-algorithm-b9144e314a72

1). Best Case Complexity: When the partitioning algorithm always chooses the middle element or near the middle element as the pivot, the best case scenario happens. Quicksort’s best-case time complexity is O (n*logn). The following is the best-case recurrence.

T(n) = 2T(n/2) + O(n)
//solution O(nLogn)
2). Average Case Complexity: This occurs when the array elements are in a disordered sequence that isn’t increasing or decreasing properly. Quicksort’s average case time complexity is O(n*logn). The following is the average-case recurrence.

T(n) = T(n/9) + T(9n/10) + O(n)
//solution O(nLogn)
3). Worst Case Complexity: The worst-case situation is when the partitioning algorithm picks the largest or smallest element as the pivot element every time. The worst-case time complexity of quicksort is O (n2). The following is the worst-case recurrence.

T(n) = T(0) + T(n-1) + O(n)
//solution O(n2)


Space complexity 

In the average case, the quicksort algorithm uses O(log n) space because the depth of the recursion tree is O(log n). In the worst case, the quicksort algorithm uses O(n) space because the depth of the recursion tree is O(n).
*/