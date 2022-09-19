#pragma once
using namespace std;
#include <string>;
#define LISTSIZE 10

struct Student
{
	int id;
	string name;
	int age;
};

class List
{
public:
	struct list {
		int tail;
		Student items[LISTSIZE];
	};

	void init(list*);
	bool isEmpty(list);
	bool isFull(list);
	void add(list*, Student item);
	int remove(list*, int value);
	int search(list*, int value);
	void showlist(list);

};