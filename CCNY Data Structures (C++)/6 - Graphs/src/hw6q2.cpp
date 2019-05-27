#ifndef __GRAPHL_CPP__
#define __GRAPHL_CPP__
#include "hw6q2.h"

// CONSTRUCTOR
template <class Item>
graphL<Item>::graphL(){
	capacity = DEF_CAP;
	list = new node<graphData>*[capacity];
	for(size_t i = 0; i < capacity; i++){
		list[i] = NULL;
	}
	label = new Item[capacity];
	count = 0;
}

template <class Item>
graphL<Item>::graphL(const graphL<Item>& source){
	capacity = source.capacity;
	count = source.count;
	label = new Item[capacity];

	list = new node<graphData>*[capacity];
	for(size_t i = 0; i < count; i++){
		if(source.list[i] != NULL){
			node<graphData>* newHead = NULL;
			node<graphData>* tail = NULL;
			node<graphData>* sourcePtr = source.list[i];
			list_copy(sourcePtr, newHead, tail);
			list[i] = newHead;
		}
		else{
			continue;
		}
	}
}
 
// MODIFICATION MEMBER FUNCTIONS
template <class Item>
void graphL<Item>::addVertex(const Item& inLabel){
	if(count < capacity){
		label[count] = inLabel;
		count++;
	}
}

template <class Item>
void graphL<Item>::addEdge(size_t source, size_t target, int weight){
	if((source < count) && (target < count) && (weight > 0)){
		graphData newData(target, weight);
		node<graphData>* newNode = new node<graphData>(newData);

		if(list[source] == NULL){
			list[source] = newNode;
		}
		else{
			node<graphData>* curr = list[source];
			node<graphData>* prev = curr;
			if(curr->data().getV() == target){
				curr->data().setW(weight);
				return;
			}
			while(curr->link() != NULL){
				curr = curr->link();
			}
			curr->set_link(newNode);
		}
	}
}

template <class Item>
void graphL<Item>::removeEdge(size_t source, size_t target){
	if((source < count) && (target < count)){
		if(list[source] == NULL){
			return;
		}
		if(list[source]->data().getV() == target){
			list_head_remove(list[source]);
			return;
		}
		node<graphData>* curr = list[source];
		while(curr->link() != NULL){
			if(curr->data().getV() == target){
				list_remove(curr);
				return;
			}
			curr = curr->link();
		}
	}
}

// CONSTANT MEMBER FUNCTIONS
template <class Item>
void graphL<Item>::print() const{
	for(size_t j = 0; j < count; j++){
		node<graphData>* curr = list[j];
		cout << label[j] << "->";
		while(curr != NULL){
			cout << curr-> data().getV() << curr->data().getW();
			if(curr->link() != NULL){
				cout << "->";
			}
			curr = curr->link();
		}
		cout << "\n";
	}
}

template <class Item>
size_t graphL<Item>::numVertices() const{
	return count;
}

template <class Item>
size_t graphL<Item>::numEdges() const{
	size_t edgeCount = 0;
	for(size_t i = 0; i < count; i++){
		node<graphData>* curr = list[i];
		if(curr == NULL){
			if(i != count-1){
				continue;
			}
		}
		else{
			while(curr != NULL){
				edgeCount++;
				curr = curr->link();
			}
		}
	}
	return edgeCount;
}

template <class Item>
bool graphL<Item>::isEdge(size_t source, size_t target) const{
	if(count > 0){
		node<graphData>* curr = list[source];
		while(curr != NULL){
			if(curr->data().getV() == target){
				return true;
			}
			curr = curr->link();
		}
		return false;
	}
}

template <class Item>
node<Item>* graphL<Item>::neighbors(size_t vertex) const{
	node<graphData>* newHead;
	if(list[vertex] != NULL){
		node<graphData>* headNode = list[vertex];
		node<graphData>* tail;
		list_copy(headNode, newHead, tail);
	}
	return newHead;
}

#endif