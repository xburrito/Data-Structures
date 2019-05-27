#! /bin/sh

g++ ./main_test_fillArray.cpp ./src/hw1.cpp -o ./build/fillArray.o

echo "Input: a"
echo "Expected Output:"
echo "a"
echo "Test Output:"
echo 'a\n#\n' | ./build/fillArray.o
echo ''

echo "Input: a b"
echo "Expected Output:"
echo "ab"
echo "Test Output:"
echo 'a\nb\n#\n' | ./build/fillArray.o
echo ''