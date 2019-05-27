#include "hw4q2.h"
#include "hw4q5.h"
#include "gtest/gtest.h"

TEST(queue, queueOp) {
    Queue<int> q1;

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

TEST(queue, copy) {
    Queue<int> q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    Queue<int> q2(q1);

    EXPECT_EQ(3, q2.size());
    EXPECT_EQ(1, q2.front());
    EXPECT_EQ(false, q2.empty());
    q2.pop();
    EXPECT_EQ(2, q2.size());
    EXPECT_EQ(2, q2.front());
    EXPECT_EQ(false, q2.empty());
    q2.pop();
    EXPECT_EQ(1, q2.size());
    EXPECT_EQ(3, q2.front());
    EXPECT_EQ(false, q2.empty());
    q2.pop();
    EXPECT_EQ(0, q2.size());
    EXPECT_EQ(true, q2.empty());

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

TEST(queue, assignment) {
    Queue<int> q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    Queue<int> q2;

    q2.push(4);
    EXPECT_EQ(1, q2.size());
    EXPECT_EQ(4, q2.front());
    EXPECT_EQ(false, q2.empty());

    q2 = q1;

    EXPECT_EQ(3, q2.size());
    EXPECT_EQ(1, q2.front());
    EXPECT_EQ(false, q2.empty());
    q2.pop();
    EXPECT_EQ(2, q2.size());
    EXPECT_EQ(2, q2.front());
    EXPECT_EQ(false, q2.empty());
    q2.pop();
    EXPECT_EQ(1, q2.size());
    EXPECT_EQ(3, q2.front());
    EXPECT_EQ(false, q2.empty());
    q2.pop();
    EXPECT_EQ(0, q2.size());
    EXPECT_EQ(true, q2.empty());
}

TEST(Queue2Stack, queueOp) {
    Queue2Stack<int> s1;

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



int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
