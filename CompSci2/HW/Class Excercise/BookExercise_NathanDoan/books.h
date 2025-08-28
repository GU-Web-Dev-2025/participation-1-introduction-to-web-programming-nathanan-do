#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <string>

using namespace std;

class Book{

    public:

        // Default constructor
        Book();

        // Parameterized constructor
        Book(string t, string a, int p);

        // Prints out specific book information
        void printbook();

        // Gets the users book information
        int getbook();
    
    private:
        string title;
        string author;
        int pages;

};

#endif