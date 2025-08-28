#include <iostream>

using namespace std;

int main(){
    int arr[5] = {2, 3, 4, 5, 6};
    int x, y;

    for (int i = 0; i < 5; i++){
        cout << "The array: " << arr[i] << endl;
    }
    
    swap(x,y);

    return 0;

}