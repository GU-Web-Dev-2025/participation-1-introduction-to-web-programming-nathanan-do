Assignment - Arrays

Your task is to complete the implementation file (.cpp) based
on the function definition found in the .h file.

The program will create 10 random numbers within a range, store
them into an integer array, and sort them.

See the comments in the .cpp and the .h files for more details.

Main has been written for you, do not modify main.

Do not modify the .h file

When you compile the starter code, you'll recieve some errors:
(Something similar to the below)

g++ BubbleSort.cpp
ld: Undefined symbols:
  printArray(int*, int), referenced from:
      _main in BubbleSort-30f3c3.o
      _main in BubbleSort-30f3c3.o
  doSort(int*, int), referenced from:
      _main in BubbleSort-30f3c3.o
  fillArray(int*, int, int, int), referenced from:
      _main in BubbleSort-30f3c3.o
error: linker command failed with exit code 1 (use -v to see invocation)

These errors will go away once you implement the missing functions in your .cpp file
Write out the "skeleton" of the functions first, then once you can successfully compile
you code, begin implementing each function.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Your expected output should look like this (with different random numbers, of course)

./BubbleSort
~~~~~Before Sorting~~~~~
[ 13 69 75 1 19 7 64 97 12 66 ]
~~~~~After Sorting~~~~~
[ 1 7 12 13 19 64 66 69 75 97 ]
