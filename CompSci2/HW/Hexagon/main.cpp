#include "hexagon.h"

void testCopyConstructor();
void testAssignmentOperator();

int main(){

    testCopyConstructor();
    testAssignmentOperator();

    return 0;
}

void testCopyConstructor(){
    std::cout << "**************************" << std::endl;
    std::cout << "TESTING: Copy Constructor " << std::endl;
    std::cout << "**************************" << std::endl << std::endl;;

    Hexagon h1(5, "Purple");
    Hexagon h2(h1);
    Hexagon h3 = h1;

    std::cout << "**************************" << std::endl;
    std::cout << "Printing Hexagons Before: " << std::endl;
    h1.printHexagon("h1");
    h2.printHexagon("h2");
    h3.printHexagon("h3");

    h1.setColor("Red");
    h2.setColor("Green");
    h3.setColor("Blue");

    std::cout << "**************************" << std::endl;
    std::cout << "Printing Hexagons After: " << std::endl;
    h1.printHexagon("h1");
    h2.printHexagon("h2");
    h3.printHexagon("h3");
}

void testAssignmentOperator(){
    std::cout << "**************************" << std::endl;
    std::cout << "TESTING: Assignment Operator" << std::endl;
    std::cout << "**************************" << std::endl << std::endl;

    Hexagon h1(1, "Grey");
    Hexagon h2(2, "Teal");
    Hexagon h3(3, "Yellow");

    std::cout << "**************************" << std::endl;
    std::cout << "Printing Hexagons Before: " << std::endl;
    h1.printHexagon("h1");
    h2.printHexagon("h2");
    h3.printHexagon("h3");

    h2 = h1;
    h3 = h1;
    h1.setColor("No Color");

    std::cout << "**************************" << std::endl;
    std::cout << "Printing Hexagons After: " << std::endl;
    h1.printHexagon("h1");
    h2.printHexagon("h2");
    h3.printHexagon("h3");
}