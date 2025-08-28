#include <iostream>
#include <vector>

using namespace std;

void swapref(int  &a, int &b);
void swappnt(int  *a, int *b);


int main(){

    int a = 3, b = 9;
    int *pnta = nullptr, *pntb = nullptr;
    pnta = &a; pntb = &b;

cout << "Before swaps: A = " << a << ", and B = " << b << endl;

    swapref(a,b);
cout << "After swapref: A = " << a << ", and B = " << b << endl;

    swappnt(pnta,pntb);

cout << "After swappnt: A = " << a << ", and B = " << b << endl;

cout << "pntr: A = " << a << ", and B = " << b << endl;

    return 0;
}

void swapref(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swappnt(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}