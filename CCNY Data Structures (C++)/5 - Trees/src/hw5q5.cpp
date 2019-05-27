#ifndef __HEAP_CPP__
#define __HEAP_CPP__
#include "hw5q5.h"

// CONSTRUCTOR
template <class Item>
Heap<Item>::Heap(){
	capacity = DEF_CAP;
	data = new Item[capacity];
	count = 0;
}

// MODIFICATION MEMBER FUNCTIONS
template <class Item>
void Heap<Item>::increaseKey(size_t i, const Item& entry){
	assert(getCount() > 0);
	if(entry > data[i]){
		data[i] = entry;
		maxHeapify(i);
	}
}

template <class Item>
Item Heap<Item>::removeMax(){
	assert(getCount() > 0);
	Item maxItem = data[0];
	data[0] = data[getCount()-1];
	count--;
	maxHeapify(0);
	return maxItem;
}

template <class Item>
void Heap<Item>::maxHeapify(const size_t& i){
	size_t largest = i;

	if(left(i) <= getCount() && data[left(i)] > data[i]){
		largest = left(i);
	}
	else{
		largest = i;
	}
	if(right(i) <= getCount() && data[right(i)] > data[i]){
		largest = right(i);
	}
	if(largest != i){
		swap(data[i], data[largest]);
		maxHeapify(largest);
	}
}

template <class Item>
void Heap<Item>::buildMaxHeap(){
	size_t counter = getCount();
	for(size_t i = getCount()-1; i >= 1; i--){
		swap(data[0], data[i]);
		counter--;
		maxHeapify(0);
	}
}

template <class Item>
Item* Heap<Item>::heapsort(){
	Item* newHeap = new Heap<Item>();
	for(size_t i = 0; i < getCount(); i++){
		newHeap->insert(data[i]);
	}
	newHeap->buildMaxHeap();
	size_t index = getCount();
	while(index > 1){
		index--;
		Item temp = data[0];
		newHeap[0] = newHeap[index];
		newHeap[index] = temp;
		newHeap.maxHeapify(index);
	}
	return newHeap;
}

template <class Item>
Item Heap<Item>::minimum(){
	assert(count > 0);
	Item minValue = INT_MAX;
	size_t newDepth = 0;
	size_t numNodes = 0;
	if(count > 1){
		newDepth = floor(log2(count))-1;
	}
	for(size_t i = 0; i <= newDepth; i++){
		numNodes += pow(2,i);
	}
	for(size_t j = 0; j < numNodes; j++){
		if(data[left(j)] == NULL){
			break;
		}
		if(data[j] < minValue){
			minValue = data[j];
		}
		if(data[left(j)] < minValue){
			minValue = data[left(j)];
		}
		if(data[right(j)] < minValue){
			minValue = data[right(j)];
		}
	}
	return minValue;
}

template <class Item>
Item Heap<Item>::maximum(){
	assert(count > 0);
	return data[0];
}

#endif