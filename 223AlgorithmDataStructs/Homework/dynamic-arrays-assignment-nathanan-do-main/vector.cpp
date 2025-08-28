/*
    *Name:              Nathan Doan
    *Last Modified:     13 Febrary 2025
    *Class:             223-01 Algorithm & Abstract Data
    *Professor:         Prof. Johnson
    
    *Program Description: Practice for dynamic arrays (vectors) and vector operations
*/

#include <vector>
#include <iostream>



void part1() {
    //TODO: Implement part 1
    std::vector<int> myVec;
    int filler;

    for(int i = 0; i < 50000; i++){
        myVec.push_back(filler);  
    }
    int myVecCapacity = myVec.capacity();


    std::cout << "SIZE: " << myVec.size() << " CAPACITY: " << myVecCapacity << std::endl;
    
    myVec.resize(myVec.size()/2);
    myVecCapacity = myVec.capacity();

    std::cout << "SIZE: " << myVec.size() << " CAPACITY: " << myVecCapacity << std::endl;

    myVec.shrink_to_fit();
    myVecCapacity = myVec.capacity();
    std::cout << "SIZE: " << myVec.size() << " CAPACITY: " << myVecCapacity << std::endl;
}

void part2() {
    //TODO: Implement part 2
    std::vector<bool> myVecBool(10000);
    std::vector<char> myVecChar(10000);

    std::cout << "Memory Usage of std::myVecBool: " << sizeof(myVecBool) << " bytes" << std::endl;
    std::cout << "Memory Usage of std::myVecChar: " << sizeof(myVecChar) << " bytes" << std::endl;
}

int main() {
    part1();
    part2();
    return 0;
}