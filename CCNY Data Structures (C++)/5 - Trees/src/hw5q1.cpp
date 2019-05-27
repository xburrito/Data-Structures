#ifndef __BTNODE_CPP__
#define __BTNODE_CPP__
#include "hw5q1.h"

//Left (ROOT) Right
template <class Process, class Item>
void inorder(Process f, btNode<Item>* nodePtr){
	if(nodePtr == NULL){
		return;
	}
	inorder(f, nodePtr->getLeft());
	f(nodePtr->getData());
	inorder(f, nodePtr->getRight());

}

//(ROOT) Left Right
template <class Process, class Item>
void preorder(Process f, btNode<Item>* nodePtr){
	if(nodePtr == NULL){
		return;
	}
	f(nodePtr->getData());
	preorder(f, nodePtr->getLeft());
	preorder(f, nodePtr->getRight());
}

//Left Right (ROOT)
template <class Process, class Item>
void postorder(Process f, btNode<Item>* nodePtr){
	if(nodePtr == NULL){
		return;
	}
	postorder(f, nodePtr->getLeft());
	postorder(f, nodePtr->getRight());
	f(nodePtr->getData());
}

template <class Item, class SizeType>
void print(btNode<Item>* nodePtr, SizeType depth){
	if(nodePtr == NULL){
		cout << "Empty\n";
	}
	else if(nodePtr->isLeaf()){
		cout << nodePtr->getData() << "LEAF\n";
	}
	else{	
		cout << nodePtr->getData() << endl;
		print(nodePtr->getLeft(), depth+1);
		print(nodePtr->getRight(), depth+1);
	}
}

template <class Item>
void clearTree(btNode<Item>*& rootPtr){
	btNode<Item>* parent;
	btNode<Item>* child;
	
	if(rootPtr == NULL){
		return;
	}

	btNode<Item>* lChild = rootPtr->getLeft();
	clearTree(lChild);
	btNode<Item>* rChild = rootPtr->getRight();
	clearTree(rChild);

	delete rootPtr;
	rootPtr = NULL;
}

template <class Item>
btNode<Item>* copyTree(const btNode<Item>* rootPtr){
	btNode<Item>* left_ptr;
	btNode<Item>* right_ptr;

	if(rootPtr == NULL){
		return NULL;
	}

	left_ptr = copyTree(rootPtr->getLeft());
	right_ptr = copyTree(rootPtr->getRight());

	return new btNode<Item>(rootPtr->getData(), left_ptr, right_ptr);
}

template <class Item>
size_t treeSize(const btNode<Item>* nodePtr){
	size_t count = 1;

	if(nodePtr->getLeft() != NULL){
		count += treeSize(nodePtr->getLeft());
	}
	if(nodePtr->getRight() != NULL){
		count += treeSize(nodePtr->getRight());
	}
	return count;
}

#endif