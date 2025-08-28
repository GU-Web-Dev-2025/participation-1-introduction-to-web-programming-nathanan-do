#include "book.h"

int main(){

    Book book1;
    Book book2("Goosebumps", "R.L. Stine", 200);

    book1.printBook();
    book2.printBook();
    std::cout << "-------------" << std::endl;

    book1.setTitle("Cat In The Hat");
    book1.setAuthor("Dr. Suess");
    book1.setPages(61);

    book1.printBook();
    book2.printBook();

    return 0;
}