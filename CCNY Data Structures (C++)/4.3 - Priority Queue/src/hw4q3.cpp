#ifndef __HW4Q3_CPP__
#define __HW4Q3_CPP__
#include "hw4q3.h"

template <class Item>
PriorityQueue<Item>::PriorityQueue(){
	capacity = DEF_CAP;
	data = new Item[DEF_CAP];
	first = 0;
	last = capacity-1;
	used = 0;
}

template <class Item>
PriorityQueue<Item>::PriorityQueue(const PriorityQueue<Item>& source){
	capacity = source.capacity;
	used = source.used;
	first = source.first;
	last = source.last;
	Item* nData = new Item[source.capacity];
	
	for(size_t i =  0; i < source.used; i++){
		nData[i] = source.data[i];
	}
	data = nData;
}

template <class Item>
PriorityQueue<Item>::~PriorityQueue(){
	delete[] data;
}

template <class Item>
void PriorityQueue<Item>::push(const Item& entry){
	if(!(used > capacity)){
		last = nextIndex(last);
		data[last] = entry;
		used++;
	}
	Item temporary;
	if(data[last] < data[first]){
		temporary = data[first];
		data[first] = data[last];
		data[last] = temporary;
	}
}

template <class Item>
void PriorityQueue<Item>::pop(){
	Item temporary;
	if(data[last] < data[nextIndex(first)]){
		temporary = data[nextIndex(first)];
		data[nextIndex(first)] = data[last];
		data[last] = temporary;
	}
	if(!(empty())){
		first = nextIndex(first);
		used--;
	}
}

template <class Item>
void PriorityQueue<Item>::operator=(const PriorityQueue<Item>& source){
	capacity = source.capacity;
	data = new Item[capacity];
	first = source.first;
	last = source.last;
	used = source.used;

	Item* nData = new Item[source.capacity];
	for(size_t i = 0; i < source.used; i++){
		nData[i] = source.data[i];
	}
	data = nData;
}

template <class Item>
size_t PriorityQueue<Item>::size() const{
	return used;
}

template <class Item>
bool PriorityQueue<Item>::empty() const{
	return (used == 0);
}

template <class Item>
Item PriorityQueue<Item>::front() const{
	if(used != 0){
		return data[first];
	}
	return Item();
}

#endif