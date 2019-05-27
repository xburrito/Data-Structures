#include <fstream>
#include "hw1.h"
#include "gtest/gtest.h"

using std::ifstream;

TEST(fizzBuzz, fizzBuzz) {
    ::testing::internal::CaptureStdout();
    fizzBuzz();
    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_STREQ("0 FizzBuzz\n1 \n2 \n3 Fizz\n4 \n5 Buzz\n6 Fizz\n7 \n8 \n9 Fizz\n10 Buzz\n11 \n12 Fizz\n13 \n14 \n15 FizzBuzz\n16 \n17 \n18 Fizz\n19 \n20 Buzz\n21 Fizz\n22 \n23 \n24 Fizz\n25 Buzz\n26 \n27 Fizz\n28 \n29 \n30 FizzBuzz\n", output.c_str());
}

TEST(highestOccurrences, oneLetter) {
    char ar[] = {'a', 'a'};
    EXPECT_EQ('a', highestOccurrences(ar, 2));
}

TEST(highestOccurrences, twoLetterDiff1) {
    char ar[] = {'a', 'a', 'b'};
    EXPECT_EQ('a', highestOccurrences(ar, 3));
}

TEST(highestOccurrences, twoLetterDiff2) {
    char ar[] = {'a', 'b', 'b'};
    EXPECT_EQ('b', highestOccurrences(ar, 3));
}

TEST(highestOccurrences, twoLetterSame) {
    char ar[] = {'a', 'a', 'b', 'b'};
    EXPECT_EQ('a', highestOccurrences(ar, 4));
}

TEST(shiftAr, noShift) {
    char ar[] = {'a', 'b', 'c', 'a', 'd', 'e', 'b', 'c', 'a'};
    char testAr[] = {'a', 'b', 'c', 'a', 'd', 'e', 'b', 'c', 'a'};
    shiftAr(testAr, 9, 0);
    for(size_t i = 0; i < 9; i++)
        EXPECT_EQ(ar[i], testAr[i]);
}

TEST(shiftAr, rightShift) {
    char ar[] = {'b', 'c', 'a', 'a', 'b', 'c', 'a', 'd', 'e'};
    char testAr[] = {'a', 'b', 'c', 'a', 'd', 'e', 'b', 'c', 'a'};
    shiftAr(testAr, 9, 3);
    for(size_t i = 0; i < 9; i++)
        EXPECT_EQ(ar[i], testAr[i]);
}

TEST(shiftAr, rightShiftGTSize) {
    char ar[] = {'b', 'c', 'a', 'a', 'b', 'c', 'a', 'd', 'e'};
    char testAr[] = {'a', 'b', 'c', 'a', 'd', 'e', 'b', 'c', 'a'};
    shiftAr(testAr, 9, 12);
    for(size_t i = 0; i < 9; i++)
        EXPECT_EQ(ar[i], testAr[i]);
}

TEST(shiftAr, leftShift) {
    char ar[] = {'a', 'b', 'c', 'a', 'd', 'e', 'b', 'c', 'a'};
    char testAr[] = {'b', 'c', 'a', 'a', 'b', 'c', 'a', 'd', 'e'};
    shiftAr(testAr, 9, -3);
    for(size_t i = 0; i < 9; i++)
        EXPECT_EQ(ar[i], testAr[i]);
}

TEST(shiftAr, leftShiftGTSize) {
    char ar[] = {'a', 'b', 'c', 'a', 'd', 'e', 'b', 'c', 'a'};
    char testAr[] = {'b', 'c', 'a', 'a', 'b', 'c', 'a', 'd', 'e'};
    shiftAr(testAr, 9, -12);
    for(size_t i = 0; i < 9; i++)
        EXPECT_EQ(ar[i], testAr[i]);
}

TEST(merge, ar1Filled) {
    char ar1[] = {'a', 'b', 'c'};
    char ar2[] = {};
    char* newAr = merge(ar1, 3, ar2, 0);
    for(size_t i = 0; i < 3; i++)
        EXPECT_EQ(ar1[i], newAr[i]);
}

TEST(merge, ar2Filled) {
    char ar1[] = {};
    char ar2[] = {'a', 'b', 'c'};
    char* newAr = merge(ar1, 0, ar2, 3);
    for(size_t i = 0; i < 3; i++)
        EXPECT_EQ(ar2[i], newAr[i]);
}

TEST(merge, bothFilled) {
    char ar1[] = {'a', 'c', 'e'};
    char ar2[] = {'b', 'd', 'f'};
    char* newAr = merge(ar1, 3, ar2, 3);
    char correct[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    for(size_t i = 0; i < 6; i++)
        EXPECT_EQ(correct[i], newAr[i]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}