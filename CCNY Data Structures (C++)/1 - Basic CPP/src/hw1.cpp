#include "hw1.h"
#include <iostream>
#include <cctype>

using namespace std;
// Put your functions/prototype here if you need to 

// Question 1
void fizzBuzz() {
	for(int i=0; i<=30; i++){
        if((i%3==0) && (i%5 == 0)){
            cout << i << " ";
            cout << "FizzBuzz" << endl;
        } 
        else{
            if(i%3 == 0){
                cout << i << " ";
                cout << "Fizz" << endl;
            }
            if(i%5 == 0){
                cout << i << " ";
                cout << "Buzz" << endl;
            }
            if((i%3 != 0) && (i%5 != 0)){
                cout << i << " " << endl;
            }
        }
        
    }
}

// Question 2
void findLargeSmall() {
    int number, small, large;
    while(cin >> number){
        if(number < 99){
            if(number < small){
                small = number;
                if(large == 0)
                    large = number;
            }
            if(number > large){
                large = number;
                if(small == 0)
                    small = number;
            }
        }
        if(number == 99){
            printLargeSmall(large, small);
            break;
        }
    }
}

// Question 3
void fillArray(char ar[], size_t& size) {
	size = 0;
    char input;
    while(cin >> input){
        if(size == MAXSIZE)
            break;
        if(!isalpha(input))
            break;
        ar[size] = input;
        size++;
    }
}

// Question 4
char highestOccurrences(const char ar[], const size_t size) {
    size_t count = 0, highestCount = 0;
    int mostOccurences = 0;

    for(size_t i = 0; i < size; i++){
        for(size_t j = 0; j < size; j++){
            if(ar[i] == ar[j])
                count++;
        }
        if(count == highestCount){
            if(((int)ar[i] - 97) < (mostOccurences - 97)){
                mostOccurences = (int)ar[i];
            } 
        }
        if(count > highestCount){
            mostOccurences = (int)ar[i];
            highestCount = count;
        }
    }
    return (char)mostOccurences;
}

void printLargeSmall(const int large, const int small) {
	cout << "The largest is " << large << endl;
	cout << "The smallest is " << small << endl;
}

// Question 5
void shiftAr(char ar[], const size_t size, const int numShift) {
    string zStr = "";
    if(numShift < 0){
        size_t numS = numShift *- 1;
        size_t numV = size + numShift;

        for(size_t i = 0; i < numV; i++)
            zStr += ar[numS + i];
        for(size_t j = 0; j < numS; j++)
            zStr += ar[j];
    }
    else{
        size_t otherHalf = size - numShift;
        for(size_t i = otherHalf; i < size; i++)
            zStr += ar[i];
        for(size_t j = 0; j < otherHalf; j++)
            zStr += ar[j];
    }
    for(size_t k = 0; k < size; k++){
        ar[k] = zStr[k];
    }
}

// Question 6
char* merge(const char ar1[], const size_t n1, const char ar2[], const size_t n2){
    size_t newSize = n1 + n2;
    char temporary;
    char* newArray = new char[newSize];

    for(size_t i = 0; i < n1; i++)
        newArray[i] = ar1[i];
    for(size_t j = 0; j < n2; j++)
        newArray[j + n1] = ar2[j];

    for(size_t k = 0; k < newSize - 1; k++){
        for(size_t l = k+1; l < newSize; l++){
            if((int)newArray[l] < (int)newArray[k]){
                temporary = newArray[k];
                newArray[k] = newArray[l];
                newArray[l] = temporary;
            }
        }
    }
    return newArray;
}

void printAr(const char ar[], const size_t size) {
	for(size_t i = 0; i < size; i++)
		cout << ar[i];
	cout << endl;
}
