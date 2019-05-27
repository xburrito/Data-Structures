#ifndef __HW4Q1_CPP__
#define __HW4Q1_CPP__
#include "hw4q1.h"

template <class Item>
Stack<Item>::Stack(){
	capacity = DEF_CAP;
	data = new Item[capacity];
	used = 0;
}

template <class Item>
Stack<Item>::Stack(const Stack& source){
	capacity = source.capacity;
	used = source.used;
	Item* nData = new Item[capacity];
	for(size_t i = 0; i < used; i++){
		nData[i] = source.data[i];
	}
	data = nData;
}

template<class Item>
Stack<Item>::~Stack(){
	delete[] data;
}

template <class Item>
void Stack<Item>::push(const Item& entry){
if (used < capacity)
	{
		data[used] = entry;
		used++;
	}	
}

template <class Item>
void Stack<Item>::pop(){
	assert(!empty());
	used--;
}

template <class Item>
void Stack<Item>::operator=(const Stack<Item>& source){
	if(this == &source){
		return;
	}
	used = source.used;
	capacity = source.capacity;
	delete[] data;
	data = new Item[capacity];
	for(size_t i = 0; i < used; i++){
		data[i] = source.data[i];
	}
}

template <class Item>
size_t Stack<Item>::size() const{
	return used;
}

template <class Item>
bool Stack<Item>::empty() const{
	return used == 0;
}

template <class Item>
Item Stack<Item>::top() const{
	return data[used-1];
}

#endif