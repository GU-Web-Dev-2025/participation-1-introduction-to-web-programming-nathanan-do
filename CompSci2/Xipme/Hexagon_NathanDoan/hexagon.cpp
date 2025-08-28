#include "hexagon.h"

// Default constructor
// Initallizes 'Haxagon' to the below values when values not specified
Hexagon::Hexagon(){
    
    sideLength = 0;
    area = 0;
    *color = "no color";

}

// Deletes hexagon class in heap
Hexagon::~Hexagon(){
    
    delete color;
    color = nullptr;

}

// Takes in parameters of hexagon class and sets and calulates all values
Hexagon::Hexagon(double sideLength, std::string color){

    this->sideLength = sideLength;
    area = 0;
    this->color = new std::string(color);   
    calculateArea();
    
}

// Allows the direct copy of one class 'hexagon' to another 
Hexagon::Hexagon(const Hexagon &original){
   
    sideLength = original.sideLength; 
    calculateArea(); // Calculates the area then sets the value 'area'

    color = new std::string; 
    *color = *original.color; // Copies color pointer
}

// Directly copies one class to another using the '=' assignment opperator
Hexagon& Hexagon::operator=(const Hexagon &original){

    if (this == &original) {  // Check for self-assignment
        return *this;
    }

    delete color;  // Free existing memory if color is a pointer
    color = new std::string(*original.color);  // Copy the string content

    area = original.area;
    sideLength = original.sideLength;

    return *this;  // Return the current object

}

// Prints hexagon and basic variables
void Hexagon::printHexagon(std::string label){

    std::cout << std::endl << "*------------------------*" << std::endl;
    std::cout << "Hexagon: " << label << std::endl;
    std::cout << "Side Length: " << sideLength << std::endl;
    std::cout << "Area: " << area << std::endl;
    std::cout << "Color: " << *color << std::endl;
    std::cout << std::endl;

}

// Sets string pointer 'color' of hexagon from a non-pointer string 'color'
void Hexagon::setColor(std::string color){
    
    delete this->color;
    this->color = new std::string(color);    

}

// Calculates the area of the hexagon
void Hexagon::calculateArea(){

    area = ( ( 3 * sqrt(3) ) / 2 ) * sideLength * sideLength;

}