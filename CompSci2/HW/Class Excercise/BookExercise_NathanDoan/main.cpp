#include "books.h"

int main(){

Book defaultbook;
Book myBook("Dragon of the Red Dawn (Magic Tree House Merlin Mission)", "Mary Pope Osborne", 144); // Set variables in myBook

cout << "C++ ''Class'' practice by Nathan Doan\n-------------------------\nHere are your default books:\n";
   
    defaultbook.printbook(); cout << endl;
    myBook.printbook(); cout << endl;

    cout << "Editing default...";
    defaultbook.getbook(); cout << endl; // edit defaultbook class

    cout << "Here are your new books:\n";
    defaultbook.printbook(); cout << endl;
    myBook.printbook(); cout << endl;

}