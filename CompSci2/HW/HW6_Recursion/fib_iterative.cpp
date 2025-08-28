#include <iostream>

using namespace std;

int fibonacci_iterative(int n) {
    if (n <= 2) {
        return 1;
    }

int a = 1, b = 1, c;
    // Loop from 3 to n to calculate the nth Fibonacci number
    for (int i = 3; i <= n; ++i) {
        c = a + b; // Calculate the next Fibonacci number
        a = b;     // Update a to the previous b
        b = c;     // Update b to the current Fibonacci number
    }
    return b;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int result = fibonacci_iterative(n);
    cout << "Fibonacci output: " << result << endl;
    return 0;
}