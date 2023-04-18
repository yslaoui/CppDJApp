// Importing STL library for input/output in the console
#include <iostream>

// main function is  the netry point to any C++ program
int main () {
    // cout means console.out
    // end of line in standard library is cross platform
    std::cout << "Hello there" << std::endl;
    return 0;
}

/*
To run the file 
g++ firstProgram.cpp produces an a.out file
./a.out runs that fikle which execute the a.out file

Running a file so as to view the assembler and the object code
g++ -S firstProgram.cpp --> generates file main.s which is assembly code ie human readable low level CPU language that CPU cannot read yet
g++ -c firstProgram.cpp --> generates main.o which is machine-readable executable code. Can be opened with hex editor extension in vscode

Summary: g++ main.cpp
- Generates assembler code
- Compiles asemble code into object code (machine readable code)
- Links that object code to imported libraries

*/
