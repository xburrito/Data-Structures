#! /bin/sh

g++ ./main_test_findLargeSmall.cpp ./src/hw1.cpp -o ./build/findLargeSmall.o

echo "Input: 1"
echo "Expected Output:"
echo "The largest is 1"
echo "The smallest is 1"
echo "Test Output:"
echo '1\n99\n' | ./build/findLargeSmall.o
echo ''

echo "Input: 1 2"
echo "Expected Output:"
echo "The largest is 2"
echo "The smallest is 1"
echo "Test Output:"
echo '1\n2\n99\n' | ./build/findLargeSmall.o
echo ''

echo "Input: 1 -1"
echo "Expected Output:"
echo "The largest is 1"
echo "The smallest is -1"
echo "Test Output:"
echo '1\n-1\n99\n' | ./build/findLargeSmall.o
echo ''