#ifndef __BT_CLASS_CPP__
#define __BT_CLASS_CPP__
#include "hw5q2.h"
#include <cctype>
#include <cmath>
#include <cstdio>

//Constructor
template <class Item>
binaryTree<Item>::binaryTree(){
	root = NULL;
	curr = root;
	count = 0;
}

//Copy Constructor
template <class Item>
binaryTree<Item>::binaryTree(const binaryTree& source){
	root = copyTree(source.root);
	count = source.size();
	curr = root;
}

//Destructor
template <class Item>
binaryTree<Item>::~binaryTree(){
	clearTree(root);
	count = 0;
	curr = NULL;
}

template <class Item>
void binaryTree<Item>::createFirstNode(const Item& entry){
	if(size() == 0){
		root = new btNode<Item>(entry);
		curr = root;
		count++;
	}
}

template <class Item>
void binaryTree<Item>::shiftToRoot( ){
	if(size() > 0){
		curr = root;
	}	
}

template <class Item>
void binaryTree<Item>::shiftUp( ){
	if(hasParent()){
		curr = curr->getParent();	
	}
}

template <class Item>
void binaryTree<Item>::shiftLeft( ){
	if(hasLeft()){
		curr = curr->getLeft();	
	}
}

template <class Item>
void binaryTree<Item>::shiftRight( ){
	if(hasRight()){
			curr = curr->getRight();	
		}
}

template <class Item>
void binaryTree<Item>::change(const Item& newEntry){
	if(size() > 0){
		curr->setData(newEntry);
	}
}

template <class Item>
void binaryTree<Item>::addLeft(const Item& entry){
	if((size() > 0) && (!hasLeft())){
		btNode<Item>* newLeft = new btNode<Item>(entry);
		newLeft->setParent(curr);
		curr->setLeft(newLeft);
		count++;
	}
}

template <class Item>
void binaryTree<Item>::removeLeft(){
	if((size() > 0 && hasLeft()) && (curr->getLeft()->isLeaf())){
		btNode<Item>* remove = curr->getLeft();
		delete remove;
		curr->setLeft(NULL);
		count--;
	} 
}

template <class Item>
void binaryTree<Item>::addRight(const Item& entry){
	if((size() > 0) && (!hasRight())){
		btNode<Item>* newRight = new btNode<Item>(entry);
		newRight->setParent(curr);
		curr->setRight(newRight);
		count++;
	}
}

template <class Item>
void binaryTree<Item>::removeRight(){
	if((size() > 0 && hasRight()) && (curr->getRight()->isLeaf())){
		btNode<Item>* remove = curr->getRight();
		delete remove;
		curr->setRight(NULL);
		count--;
	} 
}

template <class Item>
void binaryTree<Item>::setRoot( btNode<Item>* newRoot ){
	if(size() > 0){
		btNode<Item>* oldRoot = root;
		btNode<Item>* left_child = NULL;
		btNode<Item>* right_child = NULL;

		if(oldRoot->getLeft() != NULL){
			left_child = oldRoot->getLeft();
			left_child->setParent(newRoot);
		}
		if(oldRoot->getRight() != NULL){
			right_child = oldRoot->getRight();
			right_child->setParent(newRoot);
		}

		newRoot->setLeft(left_child);
		newRoot->setRight(right_child);
		count = treeSize(oldRoot);

		root = newRoot;
		delete oldRoot;
	}
}

template <class Item>
btNode<Item>* binaryTree<Item>::getNode( ){
	if(size() > 0){
		return curr;
	}
}

    // CONSTANT MEMBER FUNCTIONS
template <class Item>
size_t binaryTree<Item>::size( ) const{
	return count;
}

template <class Item>
Item binaryTree<Item>::retrieve( ) const{
	return (curr->getData());
}

template <class Item>
bool binaryTree<Item>::hasParent( ) const{
	return ((size() > 0) && (curr != root));
}

template <class Item>
bool binaryTree<Item>::hasLeft( ) const{
	return (curr->getLeft() != NULL);
}

template <class Item>
bool binaryTree<Item>::hasRight( ) const{
	return (curr->getRight() != NULL);
}   

#endif