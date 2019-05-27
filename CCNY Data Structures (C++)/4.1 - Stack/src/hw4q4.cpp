#ifndef __HW4Q4_CPP__
#define __HW4Q4_CPP__
#include "hw4q4.h"

template <class Item>
Stack2Queue<Item>::Stack2Queue(){
	used = 0;
}

template <class Item>
void Stack2Queue<Item>::push(const Item& entry){
	while(!(s1.empty())){
		s2.push(s1.top());
		s1.pop();
	}
	s2.push(entry);
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
}

template <class Item>
void Stack2Queue<Item>::pop(){
	assert(!empty());
	s1.pop();
}

template <class Item>
size_t Stack2Queue<Item>::size() const{
	return s1.size();
}

template <class Item>
bool Stack2Queue<Item>::empty() const{
	return s1.empty();
}

template <class Item>
Item Stack2Queue<Item>::front() const{
	assert(!s1.empty());
	return s1.top();
}

#endif