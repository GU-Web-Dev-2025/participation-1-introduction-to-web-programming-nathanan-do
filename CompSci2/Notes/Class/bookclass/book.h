#ifndef BOOK_H
#define BOOK_H

#include<string>
#include<iostream>

class Book{

    public:
        Book();
        Book(std::string t, std::string a, int p);

        void printBook();

        //getters
        std::string getTitle();
        std::string getAuthor();
        int getPages();

        //setters
        void setTitle(std::string t);
        void setAuthor(std::string a);
        void setPages(int p);

    private:

        std::string title;
        std::string author;
        int pages; 
};


#endif