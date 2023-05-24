/*
Write code that takes a string and turns it into double 
Wrap the line that converts into a try and catch block. Note that yhe exception is a const because ot OS not changed, and take the reference of the exception which means "I do not need to take a copy of the exception I will work with that". Note that exception belongs to the namespace of the standard library. Note that at this point we write nothing inside the catch block 
Note that the stid function does know the context so it throws an exception and gives the responsibility of dealing with that exception to the calling function 
Note that inside the catch blow we can throw the exception again to the next layer using throw e; 
*/


#include <iostream>
#include <string>

int main() 
{
    std::string word = "1234";
    try 
    {
        double number = std::stod(word);
        std::cout<< "good" << std::endl; 
    }
    catch(std::exception& e) {}
    
}

