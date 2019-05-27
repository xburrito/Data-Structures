#include "hw3.h"
#include <iostream>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstdio>

void insertHead(Node*& head, Node*& entry){
	entry->setLink(head);
	head = entry;
}
void insertTail(Node*& head, Node*& entry){
	if(head == NULL){
		entry->setLink(NULL);
		head = entry;
	}
	else if(head != NULL){
		Node *cursor  = head;
		while (cursor->getLink() != NULL){
		cursor = cursor->getLink();
		}
		entry->setLink(NULL);
		cursor->setLink(entry);
	}
}

void insertInd (Node*& head, Node*& entry, size_t pos){
	Node* cursor;
	cursor = head;
	size_t count = 1;
	
	if(head == NULL){
		head = entry;
	}
	else if(head != NULL){
		while((cursor != NULL) && (count != pos)){
			cursor = cursor->getLink();
			count++;
		}
	insert(cursor, entry);
	}
}

void insert    (Node*  prev, Node*  entry){
	entry->setLink(prev->getLink());
	prev->setLink(entry);
}

void insertHead(Node*& head, const Node::nodeDatatype& entry){
	Node *insert_ptr = new Node(entry);
	if(head != NULL){
		insert_ptr->setLink(head);
	}
	head = insert_ptr;
}

void insertTail(Node*& head, const Node::nodeDatatype& entry){
	Node *insert_ptr = new Node(entry);
	if(head == NULL){
		head = insert_ptr;
	}
	else if(head != NULL){
		Node *cursor = head;
		while(cursor->getLink() != NULL){
			cursor = cursor->getLink();
		}
		cursor->setLink(insert_ptr);
	}
}

void insertInd (Node*& head, const Node::nodeDatatype& entry, size_t pos){
	if(head == NULL){
		Node *insert_ptr = new Node(entry);
		head = insert_ptr;
	}
	else if(head != NULL){
		Node* cursor = head;
		size_t count = 1;

		while((cursor != NULL) && (count != pos)){
			cursor = cursor->getLink();
			count++;
		}

		if(count == pos){
			insert(cursor, entry);
		}

	}
}

void insert    (Node*  prev, const Node::nodeDatatype& entry){
	Node *insert_ptr = new Node(entry, prev->getLink());
	prev->setLink(insert_ptr);
}

bool isCycle(Node* head){
	Node *beginning = head;
	Node *cursor = head;

	if(head->getLink() == NULL){
		return false;
	}

	while(cursor != NULL){
		if(cursor = beginning){
			return true;
		}
		cursor = cursor->getLink();
	}
	if(cursor == NULL){
		return true;
	}
}

bool isEmpty(Node* head){
	return(head == NULL);
}

bool isValid(Node* head, size_t pos){
	Node *cursor = head;
	size_t count = 0;

	if(head == NULL){
		return false;
	}
	else if((head->getLink() == NULL) && (pos == 0)){
		return true;
	}

	while((cursor->getLink() != NULL) && (count != pos)){
		count++;
	}

	if(count == pos){
		return true;
	}
	else
		return false;
}

size_t length(Node* head){
	const Node* cursor;
	size_t answer;
	answer = 0;
	for(cursor = head; cursor != NULL; cursor = cursor->getLink()){
		++answer;
	}
	return answer;
}

Node* listLocate      (Node* head, size_t position){
	Node* cursor = head;
	size_t i;
	for(i = 1; (i < position) && (cursor != NULL); ++i){
		cursor = cursor->getLink();
	}
}
const Node* listLocate(const Node* head, size_t pos){
	const Node* cursor = head;
	size_t i;
	for(i = 1; (i < pos) && (cursor != NULL); ++i){
		cursor = cursor->getLink();
	}
}

Node* listSearch      (Node* head, const Node::nodeDatatype& target){
	Node *cursor;

	for(cursor = head; cursor != NULL; cursor = cursor->getLink())
		if(target == cursor->getData())
			return cursor;
		return NULL;
}
const Node* listSearch(const Node* head, const Node::nodeDatatype& target){
	const Node *cursor;

	for(cursor = head; cursor != NULL; cursor = cursor->getLink())
		if(target == cursor->getData())
			return cursor;
		return NULL;
}

void removeHead  (Node*& head){
	Node *remove_ptr = head;
	head = head->getLink();
	delete remove_ptr;
}

void removeTail  (Node*& head){
	Node *cursor = head;
	Node *prev = cursor;

	if(head->getLink() == NULL){
		removeHead(head);
	}
	else{
		while(cursor->getLink() != NULL){
			cursor = cursor->getLink();
		}
		prev->setLink(NULL);
		delete cursor;
	}
}

void removeInd   (Node*& head, size_t pos){
	Node *cursor;
	Node *prev;
	size_t count = 0;

	if(head->getLink() == NULL){
		removeHead(head);
	}
	else if(head != NULL){
		cursor = head;
		while(cursor->getLink() != NULL){
			prev = cursor;
			cursor = cursor->getLink();
		}
		prev->setLink(cursor->getLink());
		delete cursor;
	}
}

void remove      (Node*  prev){
	Node *remove_ptr;
	remove_ptr = prev->getLink();
	prev->setLink(remove_ptr->getLink());
	delete remove_ptr;
}

void removeAll   (Node*& head){
	Node *remove_ptr;
	Node *cursor;
	cursor = head->getLink();

	while(cursor != NULL){
		remove_ptr = cursor;
		delete remove_ptr;
		cursor = cursor->getLink();
	}
	head = NULL;
}

void removeFromTo(Node*& head, size_t from, size_t to){
	size_t count = 0;
	Node *storeVal;
	Node *remove_ptr;
	Node *cursor;
	cursor = head;
	from = from -1;

	while((cursor != NULL) && (count <= to)){
		if(count == from){
			storeVal = cursor;
		}
		else if(count > from){
			remove_ptr = cursor;
			cursor = cursor->getLink();
			delete remove_ptr;
		}
		count++;
	}
	storeVal->setLink(cursor);
}

void removeHeadTo(Node*& head, size_t to){
	Node *cursor = head;
	Node *remove_ptr;
	size_t count = 0;
	while((cursor != NULL) && (count <= to)){
		remove_ptr = cursor;
		cursor = cursor->getLink();
		delete remove_ptr;
		count ++;
	}
}

void removeToTail(Node*& head, size_t from){
	Node *remove_ptr;
	Node *cursor;
	cursor = head;
	size_t count = 0;

	while(cursor != NULL){
		if(count > from){
			remove_ptr = cursor;
			cursor = cursor->getLink();
			delete remove_ptr;
		}
		else{
			cursor = cursor->getLink();
		}
		count++;
	}

}

void reverse(Node*& head){
	Node *prev = NULL;
	Node *cursor;
	cursor = head;

	while(cursor != NULL){
			Node *nextVal = cursor->getLink();
			cursor->setLink(prev);
			prev = cursor;
			cursor = nextVal;
		}
		head = prev;
}

void print(Node* head){
	Node *cursor = head;
	if(cursor == NULL){
		cout << "The linked list is empty";
	}
	else{
		
		while(cursor != NULL){
			cout << cursor << " ";
			cursor = cursor->getLink();
			}
		}
}

void swap(Node*& head, size_t pos){
	size_t position_1, position_2;
	size_t count = 0;
	Node *n1, *n2;
	Node *prev;

	if((pos == 0) && (head->getLink() != NULL)){
		n1 = head;
		n2 = head->getLink();
		n1->setLink(n2->getLink());
		n2->setLink(n1);
		head = n2;
	}

	if((pos >= 1) && (head->getLink() != NULL)){
		Node *cursor = head;
		position_1 = pos -1;
		position_2 = pos +1;

		while(count >= position_2){
			if(count == position_1){
				prev = cursor;
			}
			else if(count == pos){
				n1 = cursor;
			}
			else if(count == position_2){
				n2 = cursor;
			}
			cursor = cursor->getLink();
			count++;
		}
		n1->setLink(n2->getLink());
		n2->setLink(n1);
		prev->setLink(n2);
	}

}
void swap(Node*& head, size_t posI, size_t posJ){
	Node *cursor;
	cursor = head;
	Node *p1, *p2, *p3, *n1, *n2;
	size_t pos1, pos2, pos3, pos4, count = 0;

	if((head->getLink() != NULL) && (posI == 0)){
		swap(head, 0);
	}

	else if((head->getLink() != NULL) && (posI >= 1)){
		pos1 = posI - 1;

		while(count <= posJ){
			if(count == pos1){
				p1 = cursor;
			}
			else if(count == posI){
				n1 = cursor;
			}
			else if(count == posJ){
				n2 = cursor;
			}
			cursor = cursor->getLink();
			count++;
		}
		n1->setLink(n2->getLink());
		n2->setLink(n1);
		p1->setLink(n2);
	}
}