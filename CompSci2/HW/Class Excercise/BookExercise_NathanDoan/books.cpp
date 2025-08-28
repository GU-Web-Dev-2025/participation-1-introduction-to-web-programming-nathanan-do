#include "books.h"

// Default class definition
Book::Book(){
    title = "default title";
    author = "default author";
    pages = 0;
};

// Parameterized class definition
Book::Book(string t, string a, int p){
    title = t;
    author = a;
    pages = p;
};

// Prints out book information
void Book::printbook(){
    cout << "Book title:   " << title << endl;
    cout << "Book author:  " << author << endl;
    cout << "Page count:   " << pages << endl;
};

// Allows to edit book class
int Book::getbook(){
/*
    cout << "Enter new title: ";
    getline(cin, title);

    cout << "Enter new author: ";
    getline(cin, author);
    
    cout << "Enter page count: ";
    cin >> pages;
*/
    title = "1984";
    author = "George Orwell";
    pages = 368;
    return 0;
};