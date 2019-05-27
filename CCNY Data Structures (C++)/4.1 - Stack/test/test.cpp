#include "hw4q1.h"
#include "hw4q4.h"
#include "gtest/gtest.h"

TEST(stack, stackOp) {
    Stack<int> s1;

    EXPECT_EQ(0, s1.size());
    EXPECT_EQ(true, s1.empty());
    s1.push(1);
    EXPECT_EQ(1, s1.size());
    EXPECT_EQ(1, s1.top());
    EXPECT_EQ(false, s1.empty());
    s1.push(2);
    EXPECT_EQ(2, s1.size());
    EXPECT_EQ(2, s1.top());
    EXPECT_EQ(false, s1.empty());
    s1.push(3);
    EXPECT_EQ(3, s1.size());
    EXPECT_EQ(3, s1.top());
    EXPECT_EQ(false, s1.empty());
    s1.pop();
    EXPECT_EQ(2, s1.size());
    EXPECT_EQ(2, s1.top());
    EXPECT_EQ(false, s1.empty());
    s1.pop();
    EXPECT_EQ(1, s1.size());
    EXPECT_EQ(1, s1.top());
    EXPECT_EQ(false, s1.empty());
    s1.pop();
    EXPECT_EQ(0, s1.size());
    EXPECT_EQ(true, s1.empty());
}

TEST(stack, copy) {
    Stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    Stack<int> s2(s1);

    EXPECT_EQ(3, s2.size());
    EXPECT_EQ(3, s2.top());
    EXPECT_EQ(false, s2.empty());
    s2.pop();
    EXPECT_EQ(2, s2.size());
    EXPECT_EQ(2, s2.top());
    EXPECT_EQ(false, s2.empty());
    s2.pop();
    EXPECT_EQ(1, s2.size());
    EXPECT_EQ(1, s2.top());
    EXPECT_EQ(false, s2.empty());
    s2.pop();
    EXPECT_EQ(0, s2.size());
    EXPECT_EQ(true, s2.empty());

    EXPECT_EQ(3, s1.size());
    EXPECT_EQ(3, s1.top());
    EXPECT_EQ(false, s1.empty());
    s1.pop();
    EXPECT_EQ(2, s1.size());
    EXPECT_EQ(2, s1.top());
    EXPECT_EQ(false, s1.empty());
    s1.pop();
    EXPECT_EQ(1, s1.size());
    EXPECT_EQ(1, s1.top());
    EXPECT_EQ(false, s1.empty());
    s1.pop();
    EXPECT_EQ(0, s1.size());
    EXPECT_EQ(true, s1.empty());
}

TEST(stack, assignment) {
    Stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    Stack<int> s2;

    s2.push(4);
    EXPECT_EQ(1, s2.size());
    EXPECT_EQ(4, s2.top());
    EXPECT_EQ(false, s2.empty());

    s2 = s1;

    EXPECT_EQ(3, s2.size());
    EXPECT_EQ(3, s2.top());
    EXPECT_EQ(false, s2.empty());
    s2.pop();
    EXPECT_EQ(2, s2.size());
    EXPECT_EQ(2, s2.top());
    EXPECT_EQ(false, s2.empty());
    s2.pop();
    EXPECT_EQ(1, s2.size());
    EXPECT_EQ(1, s2.top());
    EXPECT_EQ(false, s2.empty());
    s2.pop();
    EXPECT_EQ(0, s2.size());
    EXPECT_EQ(true, s2.empty());
}

TEST(Stack2Queue, queueOp) {
    Stack2Queue<int> q1;

    EXPECT_EQ(0, q1.size());
    EXPECT_EQ(true, q1.empty());
    q1.push(1);
    EXPECT_EQ(1, q1.size());
    EXPECT_EQ(1, q1.front());
    EXPECT_EQ(false, q1.empty());
    q1.push(2);
    EXPECT_EQ(2, q1.size());
    EXPECT_EQ(1, q1.front());
    EXPECT_EQ(false, q1.empty());
    q1.push(3);
    EXPECT_EQ(3, q1.size());
    EXPECT_EQ(1, q1.front());
    EXPECT_EQ(false, q1.empty());
    q1.pop();
    EXPECT_EQ(2, q1.size());
    EXPECT_EQ(2, q1.front());
    EXPECT_EQ(false, q1.empty());
    q1.pop();
    EXPECT_EQ(1, q1.size());
    EXPECT_EQ(3, q1.front());
    EXPECT_EQ(false, q1.empty());
    q1.pop();
    EXPECT_EQ(0, q1.size());
    EXPECT_EQ(true, q1.empty());
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
