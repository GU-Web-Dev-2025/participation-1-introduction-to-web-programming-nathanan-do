#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>

using namespace std;


class ClassA{
    public:
       void out(){
        cout << "Object A.";
    };

        int x1;
    protected:
        int y1;
    private:
        int z1;
};

class ClassB : public ClassA{
    public:
        int x2; 
    protected:
        int y2; 
    private:
        int z2; 
};

class ClassC : public ClassB{
    public:
        int x3; 
    protected:
        int y3; 
    private:
        int z3;
};






#endif