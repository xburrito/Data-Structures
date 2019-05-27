#ifndef __HW1_H__
#define __HW1_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 1 header file

// Try not to change this file

#include <iostream>
#include <cctype>

using std::cout;
using std::endl;

const size_t MAXSIZE = 50;

// Question 1
void fizzBuzz();

// Question 2
void findLargeSmall();
void printLargeSmall(const int large, const int small);

// Question 3
void fillArray(char ar[], size_t& size);

// Question 4
char highestOccurrences(const char ar[], const size_t size);

// Question 5
void shiftAr(char ar[], const size_t size, const int numShift);

// Question 6
char* merge(const char ar1[], const size_t n1, const char ar2[], const size_t n2);

// Print Array Function
void printAr(const char ar[], const size_t size);


// Following line is the end of the marco guard
#endif