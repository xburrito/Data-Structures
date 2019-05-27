#ifndef __BT_CLASS_DA_CPP__
#define __BT_CLASS_DA_CPP__
#include "hw5q3.h"

// CONSTRUCTORS and DESTRUCTOR
template <class Item>
binaryTreeDA<Item>::binaryTreeDA( ){
	capacity = DEF_CAP;
	tree = new Item[capacity];
	count = 0;
	curr = 0;
}

template <class Item>
binaryTreeDA<Item>::binaryTreeDA(const binaryTreeDA& source){
	if(source.count < DEF_CAP){
		capacity = DEF_CAP;
		count = source.count;
		curr = source.curr;
		tree = new Item[capacity];
		
		for(size_t i = 0; i < capacity; i++){
			tree[i] = source.tree[i];
		}
	}
}

template <class Item>
binaryTreeDA<Item>::~binaryTreeDA( ){
	delete[] tree;
	capacity = 0;
	count = 0;
	curr = -1;
}

// MODIFICATION MEMBER FUNCTIONS
template <class Item>
void binaryTreeDA<Item>::createFirstNode(const Item& entry){
	if(count == 0){
		tree[0] = entry;
		curr = 0;
		count = 1;
	}
}

template <class Item>
void binaryTreeDA<Item>::shiftToRoot( ){
	assert((size() > 0) && ((curr >= 0) && (curr < capacity)));
	curr = 0;
}

template <class Item>
void binaryTreeDA<Item>::shiftUp( ){
	if (hasParent()){
		curr - floor((curr-1)/2);
	}
}

template <class Item>
void binaryTreeDA<Item>::shiftLeft( ){
	if(hasLeft()){
		curr = (2 * curr) + 1;		
	}
}

template <class Item>
void binaryTreeDA<Item>::shiftRight( ){
	if(hasRight());
	curr = (2 * curr) + 2;
}

template <class Item>
void binaryTreeDA<Item>::shiftInd(const size_t& ind){
	if((count > 0) && (ind < count)){
		curr = ind;
	}
}

template <class Item>
void binaryTreeDA<Item>::change(const Item& newEntry){
	assert(size() > 0);
	tree[curr] = newEntry;
}

template <class Item>
void binaryTreeDA<Item>::addLeft(const Item& entry){
	if(!hasLeft()){
		size_t addInd = (2 * curr) + 1;
		tree[addInd] = entry;
		count++;
	}
}

template <class Item>
void binaryTreeDA<Item>::removeLeft(){
	if((count > 0) && (hasLeft())){
		size_t leftInd = (2 * curr) + 1;
		tree[leftInd] = 0;
		count--;
	}
}

template <class Item>
void binaryTreeDA<Item>::addRight(const Item& entry){
	if(!hasRight()){
		size_t addInd = (2 * curr) + 2;
		tree[addInd] = entry;
		count++;
	}
}

template <class Item>
void binaryTreeDA<Item>::removeRight(){
	if((count > 0) && (hasRight())){
		size_t rightInd = (2 * curr) + 2;
		tree[rightInd] = 0;
		count--;
	}
}

// CONSTANT MEMBER FUNCTIONS
template <class Item>
size_t binaryTreeDA<Item>::size( ) const{
	return count;
}

template <class Item>
Item binaryTreeDA<Item>::retrieve( ) const{
	assert((size() > 0) && ((curr >= 0) && (curr < capacity)));
	return tree[curr];
}

template <class Item>
bool binaryTreeDA<Item>::hasParent( ) const{
	assert((size() > 0) && ((curr >= 0) && (curr < capacity)));
	return curr != 0;
}

template <class Item>
bool binaryTreeDA<Item>::hasLeft( ) const{
	assert((size() > 0) && ((curr >= 0) && (curr < capacity)));
	return(2 * curr + 1) < count;
}

template <class Item>
bool binaryTreeDA<Item>::hasRight( ) const{
	assert((size() > 0) && ((curr >= 0) && (curr < capacity)));
	return(2 * curr + 2) < count; 
}  

#endif