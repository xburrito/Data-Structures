#ifndef __GRAPHM_CPP__
#define __GRAPHM_CPP__
#include "hw6q1.h"

// CONSTRUCTOR
template <class Item>
graphM<Item>::graphM(){
	capacity = DEF_CAP;
	label = new Item[capacity]();
	matrix = new int*[capacity];
	for(size_t i = 0; i < capacity; i++){
		matrix[i] = new int[capacity];
	}
	count = 0;
}

template <class Item>
graphM<Item>::graphM(const graphM<Item>& source){
	capacity = source.capacity;
	count = source.count;
	matrix = new int*[capacity];

	for(size_t i = 0; i < capacity; i++){
		matrix[i] = new int[capacity]();
		for(size_t j = 0; j < count; j++){
			matrix[i][j] = source.matrix[i][j];
		}
	}
	label = new Item[capacity];
	for(size_t k = 0; k < capacity; k++){
		label[k] = source.label[k];
	}
}

// MODIFICATION MEMBER FUNCTIONS
template <class Item>
void graphM<Item>::addVertex(const Item& inLabel){
	if(count < capacity){
		label[count] = inLabel;
		count++;
	}
}

template <class Item>
void graphM<Item>::addEdge(size_t source, size_t target, int weight){
	if((count > 0) && (source < capacity) && (target < capacity) && (weight > 0)){
		matrix[source][target] = weight;
	}
}
template <class Item>
void graphM<Item>::removeEdge(size_t source, size_t target){
	if((count > 0) && (source < capacity) && (target < capacity)){
		matrix[source][target] = 0;
	}
}

// CONSTANT MEMBER FUNCTIONS
template <class Item>
void graphM<Item>::print() const{
	if(count > 0){
		cout << setw(2) << "";
		for(size_t i = 0; i < count; i++){
			cout << label[i];
			cout << setw(1) << "";
		}
		cout << "\n";
			for(size_t j = 0; j < count; j++){
				cout << label[j];
				cout << setw(1) << "";
				for(size_t k = 0; k < count; k++){
					cout << matrix[j][k];
					cout << setw(1) << "";
				}
				cout << endl;
			}
	}
}

template <class Item>
size_t graphM<Item>::numVertices() const{
	return count;
}
template <class Item>
size_t graphM<Item>::numEdges() const{
	size_t edgeNum = 0;
	for(size_t i = 0; i < count; i++){
		for(size_t j = 0; j < count; j++){
			if(matrix[i][j] != 0){
				edgeNum++;
			}
		}
	}
	return edgeNum;
}

template <class Item>
bool graphM<Item>::isEdge(size_t source, size_t target) const{
	return (matrix[source][target] > 0);
}

template <class Item>
Item* graphM<Item>::neighbors(size_t vertex) const{
	if(count > 0){
		Item* aNeighbor = new Item[count]();
		size_t neighborIndex = 0;
		for(size_t i = 0; i < count; i++){
			if(matrix[vertex][i] > 0){
				aNeighbor[neighborIndex] = label[i];
				neighborIndex++;
			}
		}
		aNeighbor = resize(aNeighbor, neighborIndex);
		return aNeighbor;
	}
}
    
 #endif