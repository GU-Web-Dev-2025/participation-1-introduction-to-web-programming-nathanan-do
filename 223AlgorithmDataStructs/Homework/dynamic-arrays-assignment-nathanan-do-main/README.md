# Dynamic Array Assignment

This assignment shows your knowledge of how vectors manage its size and capacity and how the data type affects the memory usage.

## Part 1

Demonstrate size vs capacity during resizing. You may use std::vector library.

Write a program that:
1. Creates an empty vector of ints
2. Add 50,000 integers to the vector and record the size and capacity after the entire operation.
3. Removes half the elements from the vector by resizing it to half its original size (eg. resize(size() / 2)) and record the size and capacity again.
4. Calls shrink_to_fit() on the vector to optimize its memory usage and log the size and capacity again.

Your program should output the results in the following format:
``` 
After adding elements: Size = X, Capacity = Y
After resizing: Size = X, Capacity = Y
After shrink_to_fit(): Size = X, Capacity = Y
```

## Part 2

Compare memory usage of std::vector<bool> and std::vector<char>.

Write a program that:
1. Creates a std::vector<bool> with 10,000 elements.
2. Creates a std::vector<char> with 10,000 elements.
3. Calculates and prints the memory usage for each vector in bytes.
Your program should output the results in the following format:

```
Memory usage of std::vector<bool>: X bytes
Memory usage of std::vector<char>: Y bytes
```
