#include <iostream>

using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int result = factorial(n);
    cout << "Factorial output: " << result << endl;
    return 0;
}