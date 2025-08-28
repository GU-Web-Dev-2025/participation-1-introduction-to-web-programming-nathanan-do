#include <iostream>

using namespace std;

int factorial_iterative(int n) {
    int result = 1;
    // Loop from 2 to n to calculate n factorial
    for (int i = 2; i <= n; ++i) {
        result *= i; // Multiply result by the current value of i
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int result = factorial_iterative(n);
    cout << "Factorial output: " << result << endl;
    return 0;
}
