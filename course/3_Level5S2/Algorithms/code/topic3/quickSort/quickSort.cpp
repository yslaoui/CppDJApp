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
#include <cmath>
#include <vector>

void printVector(std::vector<int> vec) 
{
    for (int& elem: vec) 
    {
        std::cout << elem<< " ,"; 
    }
    std::cout << std::endl;
}

// Since we do not know the size of the left and right vecay we must use a vector
std::vector<int> quickSort(std::vector<int> vec) 
{
    // Base case
    if (vec.size() == 0 || vec.size() == 1) return vec;
    
    // Recursive case
    std::cout << "We are staring a new call of the quickSort function with this vector as argument" << std::endl;
    printVector(vec);
    int midIndex = floor(vec.size()/2);
    std::cout << "The mid index is " <<  midIndex << std::endl;
    int pivotElement = vec[midIndex];
    std::cout << "The pivot element is " <<  pivotElement << std::endl;
    std::vector<int> leftVector;
    std::vector<int> rightVector;
    std::vector<int> result;
    for (int i=0; i< vec.size(); ++i) 
    { 
        if (i != midIndex) 
        {
            if (vec[i] < pivotElement) leftVector.push_back(vec[i]);
            else rightVector.push_back(vec[i]);
        }
    }
    std::cout << "The unsorted left and right arrays are respectively" << std::endl;
    printVector(leftVector);
    printVector(rightVector);
    // return [quickSort(leftVector),pivot, quickSort(rightVector)]
    std::vector<int> sortedLeft = quickSort(leftVector);
    std::vector<int> sortedRight = quickSort(rightVector);

    std::cout << "The sorted left and right arrays are respectively" << std::endl;
    printVector(sortedLeft);
    printVector(sortedRight);
    for (int& element: sortedLeft) 
    {
        result.push_back(element);
    }
    result.push_back(pivotElement);
    for (int& element: sortedRight) 
    {
        result.push_back(element);
    }
    std::cout << "The result array at this level is" << std::endl;
    printVector(result);
    return result;
}

int main() 
{
    std::vector<int> test = {5, 4, 3, 100, 87, 65,  2, 1};
    std::cout << "The initial vector is" << std::endl;
    printVector(test);
    std::cout << "Recurrence starts ..." << std::endl;
    std::vector<int> result = quickSort(test); 
    printVector(result);
} 


