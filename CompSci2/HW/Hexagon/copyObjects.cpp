#include "rectangle.h"

/**
 * COMMENT OUT LINES AS NEEDED FOR TESTING AND STUDY 
 * 
 *  
 */

int main(){

    // Copy Constructor
    Rectangle r1(5, 3, 111);
    Rectangle r2(r1);
    Rectangle r3 = r1;

    std::cout << "r1: " << std::endl;
    r1.printRectangle();
    std::cout << std::endl << "r2: " << std::endl;
    r2.printRectangle();
    std::cout << std::endl << "r3: " << std::endl;
    r3.printRectangle();

    *r1.id = 777;

    std::cout << std::endl << std::endl << "r1: " << std::endl;
    r1.printRectangle();
    std::cout << std::endl << "r2: " << std::endl;
    r2.printRectangle();
    std::cout << std::endl << "r3: " << std::endl;
    r3.printRectangle();

    //Copy assignment Operator
    Rectangle r4(7, 5, 222);
    std::cout << std::endl << "r4 (Before copy assignment operator): " << std::endl;
    r4.printRectangle();
    r4 = r1;
    std::cout << std::endl << "r4 (After copy assignment operator): " << std::endl;
    r4.printRectangle();

    Rectangle r5(9, 8, 333);
    std::cout << std::endl << "r5 (Before copy assignment operator): " << std::endl;
    r5.printRectangle();
    r5.operator=(r1);
    std::cout << std::endl << "r5 (After copy assignment operator): " << std::endl;
    r5.printRectangle();
 
    

    return 0;
}