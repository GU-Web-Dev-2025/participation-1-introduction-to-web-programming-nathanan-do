#ifndef RECTANGLE_H
#define RECTANGLE_H

#include<iostream>
#include<string>

class Rectangle{
    public:
        // Default constructor
        Rectangle();

        // Destructor
        ~Rectangle();

        // Parameterized Constructor
        Rectangle(int length, int width, int id);

        // Copy Constructor
        Rectangle(const Rectangle &original);

        // Assignment Operator
        Rectangle& operator=(const Rectangle &original);

        // Data Members
        int length;
        int width;
        int* id;

        // Print Rectangle
        void printRectangle();
};

#endif



