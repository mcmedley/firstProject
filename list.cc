#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include "list.hh"

list_builder::list_builder() {//default constructor
	head = NULL;
	size1 = 0;
}

list_builder::~list_builder() {//destructor
	reset();
}

void list_builder::add_to_back(int value) {//add to back
	struct node* newNode = new struct node;//allocate new node
	newNode->data = value;
	newNode->next = NULL;
	struct node* temp = head;
	if (head == NULL) {
		head = newNode;
		size1++;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	size1++;
}

void list_builder::add_to_front(int value) {//add to front
	struct node* newNode = new struct node;//allocate memory for new node
	newNode->data = value;
	newNode->next = head;
	head = newNode;
	size1++;
}

void list_builder::reset() {
	struct node* temp = head;
	while (temp != NULL) {
		head = temp->next;
		delete temp;
		temp = head;
	}
	size1 = 0;
}

size_t list_builder::size() const{
	return size1;
}

struct node* list_builder::getHead() {
	return head;
}

fixed_list::fixed_list(list_builder& test) {
	intarray = new int[test.size()];
	struct node* temp = test.getHead();
	for (int i = 0; i < test.size(); i++) {
		intarray[i] = temp->data;
		temp = temp->next;
	}
	size2 = test.size();
}

fixed_list::~fixed_list() {
	delete[] intarray;
}

size_t fixed_list::size() const{
	return size2;
}

int* fixed_list::getArr() const{
	return intarray;
}

inline int fixed_list::operator[](size_t i) const {
	if (i == 0) {
		throw "Array is empty";
	}
	if (i >= size2) {
		throw "Index is out of bounds";
	}
	else {
		return intarray[i];
	}
}

std::ostream& operator<<(std::ostream& out, fixed_list& second) {
	out << "[";
	if (second.size() != 0) {
		for (int i = 0; i < second.size(); i++) {
			out << second.getArr()[i];
			if (i != second.size() - 1) {
				out << ", ";
			}
		}
	}
	out << "]";

	return out;
}

