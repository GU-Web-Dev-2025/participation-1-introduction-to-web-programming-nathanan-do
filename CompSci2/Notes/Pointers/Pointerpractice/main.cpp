#include <iostream>

using namespace std;

int main(){

    int x = 5, y = 4;

    int *xptr = nullptr, *yptr = nullptr;
    xptr = &x; yptr = &y;

    printf("The value of X: %d\n", x);
    printf("The value of xptr: %p\n", xptr);



}