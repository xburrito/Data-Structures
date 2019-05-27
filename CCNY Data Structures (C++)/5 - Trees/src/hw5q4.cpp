#ifndef __BST_CPP__
#define __BST_CPP__
#include "hw5q4.h"

template <class Item>
BST<Item>::BST(){
	count = 0;
}

template <class Item>
void BST<Item>::insert(const Item& entry){
	if(tree.size() == 0){
		tree.createFirstNode(entry);
	}
	else{
		tree.shiftToRoot();
		bool finished = false;
		while(!finished){
			if(tree.retrieve() >= entry){
				if(!tree.hasLeft()){
					tree.addLeft(entry);
					finished = true;
				}
				else if(tree.hasLeft()){
					tree.shiftLeft();
				}
			}
			if(tree.retrieve() <= entry){
				if(!tree.hasRight()){
					tree.addRight(entry);
					finished = true;
				}
				else if(tree.hasRight()){
					tree.shiftRight();
				}
			}
		}
	}
	count++;
}

template <class Item>
void BST<Item>::remove(const Item& target){
	assert(count > 0);
	tree.shiftToRoot();
	
	if(tree.retrieve() == NULL){
		return;
	}
	if(tree.retrieve() > target){
		tree.shiftLeft();
		remove(target);
	}
	if(tree.retrieve < target){
		tree.shiftRight();
		remove(target);
	}
	if(tree.retrieve == target){
		if(!tree.hasLeft()){
			transplant(tree.getNode(), tree.getRight());
			delete tree.getNode();
		}
		else{
			if(tree.getRight() == NULL){
				tree.setRoot(tree.getLeft());
				delete tree.getNode();
			}
			else if(tree.getRight() != NULL){
				while(!(!tree.hasLeft() && !tree.hasRight())){
					tree.shiftRight();
				}
				delete tree.getNode();
			}
		}
	}
}

template <class Item>
void BST<Item>::transplant(btNode<Item>*& u, btNode<Item>*& v){
	if(u->getParent() == NULL){
		tree.setRoot(v);
	}
	else if(u == (u->getParent())->getLeft()){
		u->getParent()->setLeft(v);
	}
	else{
		u->getParent()->setRight(v);
	}
	if(v != NULL){
		v->setParent(u->getParent());
	}
}

template <class Item>
btNode<Item>* BST<Item>::minimum(){
	assert(count > 0);
	tree.shiftToRoot();
	while(tree.hasLeft()){
		tree.shiftLeft();
	}
	return tree.getNode();
}

template <class Item>
btNode<Item>* BST<Item>::maximum(){
	assert(count > 0);
	tree.shiftToRoot();
	while(tree.hasRight()){
		tree.shiftRight();
	}
	return tree.getNode();
}

template <class Item>
btNode<Item>* BST<Item>::search(const Item& target){
	tree.shiftToRoot();
	assert(count > 0);
	while(!(!tree.hasLeft() && !tree.hasRight())){
		if((tree.getNode() != NULL) && (tree.retrieve() == target)){
			return tree.getNode();
		}
		if(target < tree.retrieve()){
			tree.shiftLeft();
		}
		else{
			tree.shiftRight();
		}
	}
	return NULL;
}

#endif