#include <iostream>

using namespace std;

int main ()
{

    int array[5] = {18, 29 , 39 , 19, 20};

    for(int i; i < 5; i++)
    {

        cout << array[i] << " -> " << (array + i) <<endl;

    }

    return 0;

}