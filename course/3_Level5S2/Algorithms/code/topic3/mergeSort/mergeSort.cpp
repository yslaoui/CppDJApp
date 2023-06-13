#include <iostream>
#include <cmath>

void printArray(int* arr, int size) 
{
    for (int i=0; i<size; ++i) 
    {
        std::cout << arr[i] << " ,";
    }
    std::cout << std::endl; 
}


/** merges two sorted arrays into one sorted array*/
void merge(int* arr, int size, int* helper, int low, int mid, int high) 
{
    for (int i=low; i<= high; ++i) 
    {
        helper[i] = arr[i];
    }
    printArray(helper, size);
    int helperLeft = low;
    int helperRight = mid + 1;
    int curr = low;
    while (helperLeft <= mid && helperRight <= high && curr <= high) 
    {                 
        if (helper[helperLeft] <  helper[helperRight]) 
        {
            arr[curr] = helper[helperLeft];
            helperLeft++;
        }  
        else 
        {
            arr[curr] = helper[helperRight];
            helperRight++;
        }
        curr ++;             
    }
    std::cout << "curr " << curr << std::endl;
    std::cout << "helperLeft " << helperLeft << std::endl;
    std::cout << "helperRight " << helperRight << std::endl;
    std::cout << "mid " << mid << std::endl;
    if (helperLeft <= mid) 
    {
        int remainder = mid - helperLeft + 1;
        for (int i=0; i< remainder; ++i) 
        {
            arr[curr] = helper[helperLeft + i];
            curr ++;
        }
    }
}

/** recursive call to mergeSort based on indices */
void mergeSort(int* arr, int size,  int low, int high) 
{
    if (low < high) 
    {
        int mid = low + floor((high - low)/2);
        int* helper = new int[size];
        mergeSort(arr, size, low, mid);
        mergeSort(arr, size, mid+1, high);
        merge(arr, size,  helper, low, mid, high);
    } 
}

/** High level interface*/
void mergeSort(int* arr, int size) 
{
    mergeSort(arr, size, 0, size-1);
}

/*
int main() 
{
     int size = 5;
    int* myArr = new int[size] {5, 4, 3, 2, 1};
    std::cout << "The initial array is" << std::endl; 
    printArray(myArr, size);
      // Delete the dynamic array
    mergeSort(myArr, size);
    printArray(myArr, size);
    delete[] myArr;
    return 0;

    // Testing merge
}

*/