#include "hw4q3.h"
#include "gtest/gtest.h"

TEST(queue, queueOp) {
    PriorityQueue<int> q1;

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

TEST(queue, priority) {
    PriorityQueue<int> q1;

    EXPECT_EQ(0, q1.size());
    EXPECT_EQ(true, q1.empty());
    q1.push(3);
    EXPECT_EQ(1, q1.size());
    EXPECT_EQ(3, q1.front());
    EXPECT_EQ(false, q1.empty());
    q1.push(2);
    EXPECT_EQ(2, q1.size());
    EXPECT_EQ(2, q1.front());
    EXPECT_EQ(false, q1.empty());
    q1.push(1);
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
    PriorityQueue<int> q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    PriorityQueue<int> q2(q1);

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
    PriorityQueue<int> q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    PriorityQueue<int> q2;

    q2.push(4);
    EXPECT_EQ(1, q1.size());
    EXPECT_EQ(4, q1.front());
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}