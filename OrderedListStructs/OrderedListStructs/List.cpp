#include "List.h"
#include <iostream>

void List::init(list* a_list)
{
	a_list->tail = 0;
}

void List::showlist(list a_list)
{
	if (isEmpty(a_list))
	{
		printf("List is empty");
	}
	else
	{
		int i;
		printf("value of tail %d\n ", a_list.tail);
		for (i = 0; i < a_list.tail; i++)
		{
			cout << "Index: " << i << " ID: " << a_list.items[i].id << " Name: " << a_list.items[i].name << " Age: " << a_list.items[i].age << endl;
		}
	}
}


int List::search(list* a_list, int value)
{
	if (isEmpty(*a_list))
	{
		printf("List is empty");
	}
	else
	{
		int index = 0;

		while (index < a_list->tail)
		{
			if (a_list->items[index].id == value)
			{
				return index;
			}
			else
			{
				index++;
			}
		}
		return -1;
	}
}

void List::add(list* a_list, Student item)
{
	if (isFull(*a_list))
	{
		printf("List is full");
	}
	else
	{
		a_list->items[a_list->tail] = item;
		int index = a_list->tail;

		while (index > 0)
		{
			if (a_list->items[index].id < a_list->items[index - 1].id)
			{
				Student store = a_list->items[index - 1];
				a_list->items[index - 1] = a_list->items[index];
				a_list->items[index] = store;
				index--;
			}
			else
			{
				index = 0;
			}
		}
		a_list->tail++;
	}
}

int List::remove(list* a_list, int value)
{
	if (isEmpty(*a_list))
	{
		std::cout << "List is empty\n";
	}
	else
	{
		int index = search(a_list, value);
		Student temp = a_list->items[index];

		if (index >= 0)
		{
			while (index < a_list->tail - 1)
			{
				a_list->items[index] = a_list->items[index + 1];
				index++;
			}
			a_list->tail--;
			return temp.id;

		}
		else
		{
			return -1;
		}

	}
}

bool List::isEmpty(list a_list)
{
	if (a_list.tail <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
};

bool List::isFull(list a_list)
{
	if (a_list.tail < LISTSIZE)
	{
		return false;
	}
	else
	{
		return true;
	}
};