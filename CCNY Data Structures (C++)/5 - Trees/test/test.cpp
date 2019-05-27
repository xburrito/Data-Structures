#include "hw5q1.h"
#include "hw5q2.h"
#include "hw5q3.h"
#include "hw5q4.h"
#include "hw5q5.h"
#include "gtest/gtest.h"

TEST(btClass, constructor) {
    binaryTree<int> bt;

    EXPECT_EQ(0, bt.size());
}

TEST(btClass, copy1) {
    binaryTree<int> source;
    source.createFirstNode(1);
    binaryTree<int> bt(source);

    EXPECT_EQ(1, bt.size());
}

TEST(btClass, copy2) {
    binaryTree<int> source;
    source.createFirstNode(1);
    source.addLeft(2);
    source.addRight(3);
    binaryTree<int> bt(source);

    EXPECT_EQ(3, bt.size());
}

TEST(btClass, createFirstNode) {
    binaryTree<int> bt;
    bt.createFirstNode(1);

    EXPECT_EQ(1, bt.size());
    EXPECT_EQ(1, bt.retrieve());
}

TEST(btClass, left) {
    binaryTree<int> bt;
    bt.createFirstNode(1);
    bt.addLeft(2);

    EXPECT_EQ(2, bt.size());
    EXPECT_EQ(1, bt.retrieve());
    EXPECT_EQ(true, bt.hasLeft());
    bt.shiftLeft();
    EXPECT_EQ(2, bt.retrieve());
    EXPECT_EQ(true, bt.hasParent());
    bt.shiftToRoot();
    bt.removeLeft();
    EXPECT_EQ(1, bt.size());
    EXPECT_EQ(1, bt.retrieve());
}

TEST(btClass, right) {
    binaryTree<int> bt;
    bt.createFirstNode(1);
    bt.addRight(2);

    EXPECT_EQ(2, bt.size());
    EXPECT_EQ(1, bt.retrieve());
    EXPECT_EQ(true, bt.hasRight());
    bt.shiftRight();
    EXPECT_EQ(2, bt.retrieve());
    EXPECT_EQ(true, bt.hasParent());
    bt.shiftUp();
    bt.removeRight();
    EXPECT_EQ(1, bt.size());
    EXPECT_EQ(1, bt.retrieve());
}

TEST(btClass, change) {
    binaryTree<int> bt;
    bt.createFirstNode(1);

    EXPECT_EQ(1, bt.size());
    EXPECT_EQ(1, bt.retrieve());
    EXPECT_EQ(false, bt.hasLeft());
    EXPECT_EQ(false, bt.hasRight());
    bt.change(2);
    EXPECT_EQ(2, bt.retrieve());
}

TEST(btDAClass, constructor) {
    binaryTreeDA<int> bt;
    
    EXPECT_EQ(0, bt.size());
}

TEST(btDAClass, copy1) {
    binaryTreeDA<int> source;
    source.createFirstNode(1);
    binaryTreeDA<int> bt(source);
    
    EXPECT_EQ(1, bt.size());
}

TEST(btDAClass, copy2) {
    binaryTreeDA<int> source;
    source.createFirstNode(1);
    source.addLeft(2);
    source.addRight(3);
    binaryTreeDA<int> bt(source);

    EXPECT_EQ(3, bt.size());
}

TEST(btDAClass, createFirstNode) {
    binaryTreeDA<int> bt;
    bt.createFirstNode(1);

    EXPECT_EQ(1, bt.size());
    EXPECT_EQ(1, bt.retrieve());
}

TEST(btDAClass, left) {
    binaryTreeDA<int> bt;
    bt.createFirstNode(1);
    bt.addLeft(2);

    EXPECT_EQ(2, bt.size());
    EXPECT_EQ(1, bt.retrieve());
    EXPECT_EQ(true, bt.hasLeft());
    bt.shiftLeft();
    EXPECT_EQ(2, bt.retrieve());
    EXPECT_EQ(true, bt.hasParent());
    bt.shiftToRoot();
    bt.removeLeft();
    EXPECT_EQ(1, bt.size());
    EXPECT_EQ(1, bt.retrieve());
}

TEST(btDAClass, right) {
    binaryTreeDA<int> bt;
    bt.createFirstNode(1);
    bt.addLeft(2);
    bt.addRight(3);

    EXPECT_EQ(3, bt.size());
    EXPECT_EQ(1, bt.retrieve());
    EXPECT_EQ(true, bt.hasRight());
    bt.shiftRight();
    EXPECT_EQ(3, bt.retrieve());
    EXPECT_EQ(true, bt.hasParent());
    bt.shiftUp();
    bt.removeRight();
    EXPECT_EQ(2, bt.size());
    EXPECT_EQ(1, bt.retrieve());
}

TEST(btDAClass, change) {
    binaryTreeDA<int> bt;
    bt.createFirstNode(1);

    EXPECT_EQ(1, bt.size());
    EXPECT_EQ(1, bt.retrieve());
    EXPECT_EQ(false, bt.hasLeft());
    EXPECT_EQ(false, bt.hasRight());
    bt.change(2);
    EXPECT_EQ(2, bt.retrieve());
}

TEST(BSTClass, constructor) {
    BST<int> bst;

    EXPECT_EQ(0, bst.getCt());
}

TEST(BSTClass, insert1) {
    BST<int> bst;
    bst.insert(1);

    EXPECT_EQ(1, bst.getCt());
    EXPECT_EQ(1, bst.getTree().retrieve());
}

TEST(BSTClass, insert2) {
    BST<int> bst;
    bst.insert(1);
    bst.insert(2);

    EXPECT_EQ(2, bst.getCt());
    EXPECT_EQ(1, bst.getTree().retrieve());
    EXPECT_EQ(true, bst.getTree().hasRight());
    EXPECT_EQ(false, bst.getTree().hasLeft());
}

TEST(BSTClass, insert3) {
    BST<int> bst;
    bst.insert(2);
    bst.insert(1);

    EXPECT_EQ(2, bst.getCt());
    EXPECT_EQ(2, bst.getTree().retrieve());
    EXPECT_EQ(false, bst.getTree().hasRight());
    EXPECT_EQ(true, bst.getTree().hasLeft());
}

TEST(BSTClass, insert4) {
    BST<int> bst;
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);

    EXPECT_EQ(3, bst.getCt());
    EXPECT_EQ(2, bst.getTree().retrieve());
    EXPECT_EQ(true, bst.getTree().hasRight());
    EXPECT_EQ(true, bst.getTree().hasLeft());
}

TEST(BSTClass, minmax) {
    BST<int> bst;
    bst.insert(3);
    bst.insert(2);
    bst.insert(1);
    bst.insert(4);
    bst.insert(5);

    EXPECT_EQ(5, bst.getCt());
    EXPECT_EQ(1, bst.minimum()->getData());
    EXPECT_EQ(5, bst.maximum()->getData());
}

TEST(BSTClass, search) {
    BST<int> bst;
    bst.insert(3);
    bst.insert(2);
    bst.insert(1);
    bst.insert(4);
    bst.insert(5);

    EXPECT_EQ(5, bst.getCt());
    ASSERT_EQ(nullptr, bst.search(6));
    ASSERT_EQ(nullptr, bst.search(0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}