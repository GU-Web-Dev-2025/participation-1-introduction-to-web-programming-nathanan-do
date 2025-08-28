#include "book.h"

Book::Book(){
    title = "Default Title";
    author = "Default Author";
    pages = 0;
}

Book::Book(std::string t, std::string a, int p){
    title = t;
    author = a;
    pages = p;

}

void Book::printBook(){
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Pages: " << pages << std::endl;
}

//getters
std::string Book::getTitle(){
    return title;
}

std::string Book::getAuthor(){
    return author;
}

int Book::getPages()
{
    return pages;
}

//setters
void Book::setTitle(std::string t){
    title = t;
}

void Book::setAuthor(std::string a){
    author = a;
}

void Book::setPages(int p){
    pages = p;
}   