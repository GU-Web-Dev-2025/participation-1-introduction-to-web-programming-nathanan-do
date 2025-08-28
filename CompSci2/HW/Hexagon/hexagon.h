#ifndef HEXAGON_H
#define HEXAGON_H

#include<string>
#include<iostream>
#include<cmath>

class Hexagon{

    public:

        // Default Constructor
        Hexagon();

        // Destructor
        ~Hexagon();

        // Parameterized Constructor
        Hexagon(double sideLength, std::string color);

        // Copy Constructor
        Hexagon(const Hexagon &original);

        // Copy Assignment Operator
        Hexagon& operator=(const Hexagon &original);

        // Hexagon Printer
        // Print the sideLength, area, and color of the hexagon to stdout
        void printHexagon(std::string label);

        // set the color of the hexagon
        void setColor(std::string color);

        // getter for the color
        std::string getColor();

    private:
        double sideLength;
        double area;
        std::string * color;

        // Private function to calculate the area of the hexagon
        // Call this function from the constructors during object creation
        void calculateArea();

};



#endif