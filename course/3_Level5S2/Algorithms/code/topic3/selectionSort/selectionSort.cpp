/*
0- Explain the intuition behind the algorithm
1- Categorize the algorithm: 
    Is it a comparison or non comparison algorithm ?
    Is it a recurrence algorithm ?  
1- Code the  algorithm 
1bis - where did we perform the comparison ?
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
    std::cout << std::endl; 
}

int findMin(int* arr, int size, int start) 
{
    int min = start;
    for (int i=start+1; i< size; ++i) 
    {
        if(arr[i] < arr[min]) 
        {
            min = i;
        }
    }
    return min;
}

int* swap(int* arr, int i, int j) 
{
    int c = arr[i];
    arr[i] = arr[j];
    arr[j] = c;
    return arr;
}


int* selectionSort(int* arr, int size) 
{
    for (int i=0; i< size; ++i)
    {
        int min  = findMin(arr, size, i);
        if (arr[min] < arr[i]) 
        {
            swap(arr, i, min);
        }
    }   
    return arr;
}



int main() 
{
    int size = 5;
    int* myArr = new int[size] {5, 4, 3, 2, 1};
    std::cout << "The initial array is" << std::endl; 
    printArray(myArr, size);
    int start = 0;
    int testMin  = findMin(myArr, size, start);
    std::cout << "the index of the minimum value between position " << start << " and " << size-1 << " is " << testMin <<" expected " << 4 << std::endl;
    int* testSwap = swap(myArr, 2, 4);
    std::cout << "swapping indices " << 2 << " and " << 4 << "expecting" << "[5, 4, 1, 2, 3] result is " << std::endl;
    printArray(testSwap, size);
    std::cout << "The sorted array is" << std::endl;     
    int* testSelectionSort =  selectionSort(myArr, size);
    printArray(testSelectionSort, size);
}

/*
0- Explain the intuition behind the algorithm: you find the min at each step
1- Categorize the algorithm: 
    Is it a comparison or non comparison algorithm ? comparison
    Is it a recurrence algorithm ?   non recursive
1- Code the  algorithm 
1bis - where did we perform the comparison ? in the finMin function
2- What is the best and worst case time complexity : best and worst O(n2) because the two for loops are traversed with any input
3- What is the space complexity. Is it an inp place or out of place sorting algorithm ? O(1) because you create only one variable min
*/