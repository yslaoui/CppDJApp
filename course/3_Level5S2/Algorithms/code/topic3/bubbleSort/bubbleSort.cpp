/*
0- Explain the intuition behind the algorithm
1- Categorize the algorithm: 
    Is it a comparison or non comparison algorithm ?
    Is it a recurrence algorithm ?  
1- Code the bubble sort algorithm
2- What is the best and worst case time complexity 
3- What is the space complexity. Is it an inp place or out of place sorting algorithm ?
*/

#include <iostream>


/** helper function - swaps to elements of an array*/
int* swap(int* arr, int first, int second) 
{
    int saved = arr[first];
    arr[first] = arr[second];
    arr[second] = saved;
    return arr;
}

/** helper function - prints elements of an array*/
void printArray(int* arr, int size) 
{
    for (int i=0; i< size; ++i) 
    {
        std::cout << arr[i] << ", "; 
    }
    std::cout << std::endl;
}

int* bubbleSort(int* arr, int size) 
{
    int j = size;
    bool swapped = true;
    while(j > 0 && swapped) 
    {   
        swapped = false;
        for (int i=0; i<j-1; ++i) 
        {
            if (arr[i] > arr[i+1]) 
            {
                swap(arr, i, i+1);
                swapped = true;
            }  
        } 
        j--;
    } 
    return arr;
}



/*
Answers
0- Explain the intuition behind the algorithm: the max number bubbles up
1- Categorize the algorithm: 
    Is it a comparison or non comparison algorithm ? comparison
    Is it a recurrence algorithm ?   non recursive
1- Code the bubble sort algorithm
2- What is the best and worst case time complexity best O(n) worst O(n2) 
3- What is the space complexity. Is it an inplace or out of place sorting algorithm ? O(1) in place. It creates one extra variable to perform the swap, that variable is local to swap() so it gets erased at the end of each call.
*/