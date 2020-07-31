#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>

struct node {
	int data;
	node* next;
};

class list_builder {
	struct node* head;
	size_t size1;
public:
	list_builder();
	~list_builder();

	void add_to_front(int value);
	void add_to_back(int value);
	void reset();
	size_t size() const;
	struct node* getHead();
private:
	list_builder& operator=(const list_builder&) = delete;//disable assignment
	list_builder(const list_builder& c);//disable copying
};

class fixed_list {
	int* intarray;
	size_t size2;
public:
	fixed_list(list_builder& test);
	~fixed_list();

	size_t size() const;
	int* getArr() const;
	inline int operator[](size_t i) const;
	friend std::ostream& operator<<(std::ostream& out, fixed_list& second);
private:
	fixed_list& operator=(const fixed_list&) = delete;//disable assignment
	fixed_list(const fixed_list& c);//disable copying
};

#endif
