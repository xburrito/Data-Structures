#include "hw3.h"
#include "gtest/gtest.h"

TEST(insertNode, head0) {
    Node *head;
    head = NULL;
    
    Node *node0 = new Node(0);

    insertHead(head, node0);
    EXPECT_EQ(0, head->getData());
}

TEST(insertNode, head1) {
    Node *head;
    head = NULL;
    
    Node *node0 = new Node(0);
    Node *node1 = new Node(1);

    insertHead(head, node1);
    insertHead(head, node0);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(1, head->getLink()->getData());
}

TEST(insertNode, tail0) {
    Node *head;
    head = NULL;
    
    Node *node0 = new Node(0);

    insertTail(head, node0);
    EXPECT_EQ(0, head->getData());
}

TEST(insertNode, tail1) {
    Node *head;
    head = NULL;
    
    Node *node0 = new Node(0);
    Node *node1 = new Node(1);

    insertTail(head, node0);
    insertTail(head, node1);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(1, head->getLink()->getData());
}

TEST(insertNode, ind0) {
    Node *head;
    head = NULL;
    
    Node *node0 = new Node(0);

    insertInd(head, node0, 0);
    EXPECT_EQ(0, head->getData());
}

TEST(insertNode, ind1) {
    Node *head;
    head = NULL;
    
    Node *node0 = new Node(0);
    Node *node1 = new Node(1);

    insertInd(head, node0, 0);
    insertInd(head, node1, 1);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(1, head->getLink()->getData());
}

TEST(insertNode, ind2) {
    Node *head;
    head = NULL;
    
    Node *node0 = new Node(0);
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);

    insertInd(head, node0, 0);
    insertInd(head, node2, 1);
    insertInd(head, node1, 1);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(1, head->getLink()->getData());
    EXPECT_EQ(2, head->getLink()->getLink()->getData());
}

TEST(insertEntry, head0) {
    Node *head;
    head = NULL;

    insertHead(head, 0);
    EXPECT_EQ(0, head->getData());
}

TEST(insertEntry, head1) {
    Node *head;
    head = NULL;

    insertHead(head, 1);
    insertHead(head, 0);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(1, head->getLink()->getData());
}

TEST(insertEntry, tail0) {
    Node *head;
    head = NULL;

    insertTail(head, 0);
    EXPECT_EQ(0, head->getData());
}

TEST(insertEntry, tail1) {
    Node *head;
    head = NULL;

    insertTail(head, 0);
    insertTail(head, 1);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(1, head->getLink()->getData());
}

TEST(insertEntry, ind0) {
    Node *head;
    head = NULL;

    insertInd(head, 0, 0);
    EXPECT_EQ(0, head->getData());
}

TEST(insertEntry, ind1) {
    Node *head;
    head = NULL;

    insertInd(head, 0, 0);
    insertInd(head, 1, 1);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(1, head->getLink()->getData());
}

TEST(insertEntry, ind2) {
    Node *head;
    head = NULL;

    insertInd(head, 0, 0);
    insertInd(head, 2, 1);
    insertInd(head, 1, 1);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(1, head->getLink()->getData());
    EXPECT_EQ(2, head->getLink()->getLink()->getData());
}

TEST(removeEntry, head0) {
    Node *head;
    head = NULL;

    insertHead(head, 0);
    removeHead(head);
    EXPECT_EQ(NULL, head);
}

TEST(removeEntry, head1) {
    Node *head;
    head = NULL;

    insertHead(head, 1);
    insertHead(head, 0);
    removeHead(head);
    EXPECT_EQ(1, head->getData());
    EXPECT_EQ(NULL, head->getLink());
}

TEST(removeEntry, tail0) {
    Node *head;
    head = NULL;

    insertHead(head, 0);
    removeTail(head);
    EXPECT_EQ(NULL, head);
}

TEST(removeEntry, tail1) {
    Node *head;
    head = NULL;

    insertHead(head, 1);
    insertHead(head, 0);
    removeTail(head);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(NULL, head->getLink());
}

TEST(removeEntry, ind0) {
    Node *head;
    head = NULL;

    insertHead(head, 0);
    removeInd(head, 0);
    EXPECT_EQ(NULL, head);
}

TEST(removeEntry, ind1) {
    Node *head;
    head = NULL;

    insertHead(head, 1);
    insertHead(head, 0);
    removeInd(head, 1);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(NULL, head->getLink());
}

TEST(removeEntry, all) {
    Node *head;
    head = NULL;

    insertHead(head, 1);
    insertHead(head, 0);
    removeAll(head);
    EXPECT_EQ(NULL, head);
}

TEST(isCycle, cycle) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    Node *node1 = new Node(1, node0);
    insertHead(head, node0);
    node0->setLink(node1);
    EXPECT_EQ(true, isCycle(head));
}

TEST(isCycle, notCycle) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    insertHead(head, node0);
    EXPECT_EQ(false, isCycle(head));
}

TEST(isEmpty, empty) {
    Node *head;
    head = NULL;

    EXPECT_EQ(true, isEmpty(head));
}

TEST(isEmpty, notEmpty) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    insertHead(head, node0);
    EXPECT_EQ(false, isEmpty(head));
}

TEST(isValid, valid) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    insertHead(head, node0);
    EXPECT_EQ(true, isValid(head,0));
}

TEST(isValid, notValid) {
    Node *head;
    head = NULL;

    EXPECT_EQ(false, isValid(head,0));
}

TEST(length, len0) {
    Node *head;
    head = NULL;

    EXPECT_EQ(0, length(head));
}

TEST(length, len1) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    insertHead(head, node0);
    EXPECT_EQ(1, length(head));
}

TEST(reverse, reverse) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    insertHead(head, node0);
    insertHead(head, node1);
    insertHead(head, node2);
    reverse(head);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(1, head->getLink()->getData());
    EXPECT_EQ(2, head->getLink()->getLink()->getData());
}

TEST(swap, iPlusOne0) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    insertHead(head, node0);
    swap(head, 0);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(NULL, head->getLink());
}

TEST(swap, iPlusOne1) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    Node *node1 = new Node(1);
    insertHead(head, node0);
    insertHead(head, node1);
    swap(head, 0);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(1, head->getLink()->getData());
}

TEST(swap, iPlusOne2) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    insertHead(head, node0);
    insertHead(head, node1);
    insertHead(head, node2);
    swap(head, 1);
    EXPECT_EQ(2, head->getData());
    EXPECT_EQ(0, head->getLink()->getData());
    EXPECT_EQ(1, head->getLink()->getLink()->getData());
}

TEST(swap, ij0) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    insertHead(head, node0);
    swap(head, 0, 1);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(NULL, head->getLink());
}

TEST(swap, ij1) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    Node *node1 = new Node(1);
    insertHead(head, node0);
    insertHead(head, node1);
    swap(head, 0, 1);
    EXPECT_EQ(0, head->getData());
    EXPECT_EQ(1, head->getLink()->getData());
}

TEST(swap, ij2) {
    Node *head;
    head = NULL;

    Node *node0 = new Node(0);
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    insertHead(head, node0);
    insertHead(head, node1);
    insertHead(head, node2);
    swap(head, 1, 2);
    EXPECT_EQ(2, head->getData());
    EXPECT_EQ(0, head->getLink()->getData());
    EXPECT_EQ(1, head->getLink()->getLink()->getData());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}