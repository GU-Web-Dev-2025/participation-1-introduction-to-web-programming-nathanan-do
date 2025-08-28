#include "rectangle.h"

// Default Constructor
Rectangle::Rectangle(){
    std::cout << "Default Constructor Called!" << std::endl;
    length = 0;
    width = 0;
    id = nullptr;
}

// Destructor
Rectangle::~Rectangle(){
    std::cout << "Destructor Called!" << std::endl;
    delete id;
    id = nullptr;
}

// Parameterized Constructor
Rectangle::Rectangle(int length, int width, int id){
    std::cout << "Parameterized Constructor Called!" << std::endl;
    this->length = length;
    this->width = width;
    this->id = new int;
    *this->id = id;
}

// Copy Constructor
Rectangle::Rectangle(const Rectangle &original){
    std::cout << "Copy Constructor Called!" << std::endl;
    length = original.length;
    width = original.width;
    id = new int;
    *id = *original.id;
}

// Copy Assignment Operator
Rectangle& Rectangle::operator=(const Rectangle &original){
    std::cout << "Copy Assignment Operator Called!" << std::endl;
    if(this != &original){
        length = original.length;
        width = original.width;
        delete id;
        id = new int;
        *id = *original.id;
    }
    return *this;
} 

void Rectangle::printRectangle(){
    std::cout << "Length: " << length << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "ID: " << *id << std::endl;
}