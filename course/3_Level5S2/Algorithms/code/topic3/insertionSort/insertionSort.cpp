/*
0- Explain the intuition behind the algorithm
1- Categorize the algorithm: 
    Is it a comparison or non comparison algorithm ?
    Is it a recurrence algorithm ?  
1- Code the bubble sort algorithm-² 
2- What is the best and worst case time complexity 
3- What is the space complexity. Is it an inp place or out of place sorting algorithm ?
*/

#include <iostream>

void printArray(int* arr, int size) 
{
    for (int i=0; i<size; ++i) 
    {
        std::cout << arr[i] << " ,";
    }
}


int* insertionSort(int* arr, int size) 
{
    for (int i=1; i<size; ++i) 
    {
        int ins = arr[i];
        int j = i - 1;
        while (j > -1 && ins < arr[j]) 
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = ins;
    }
    return arr;
}


int main() 
{
    int size = 5;
    int* test = new int[5] {5, 4, 3, 2, 1};
    int* result = insertionSort(test, size);
    printArray(result, size);
    return 0;
}

/* ANSWERS: 
0- Explain the intuition behind the algorithm
1- Categorize the algorithm: 
    Is it a comparison or non comparison algorithm ? Comparison
    Is it a recurrence algorithm ?  Non recurrence
1- Code the  algorithm-² 
2- What is the best and worst case time complexity Best  best O(n) worst O(n2)
3- What is the space complexity. Is it an inp place or out of place sorting algorithm ? O(1)
*/