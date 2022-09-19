#include "StdAfx.h"
#include "UList.h"

#include <iostream>

UList::UList(void)
{
	tail = 0;
}

bool UList::IsEmpty()
{
	return (tail == 0);
}

bool UList::IsFull()
{
	return (tail >= ULIST_SIZE);
}

int UList::GetSize()
{
	return tail;
}

int UList::Show(int idx)
{
	return m_items[idx];
}

void UList::DisplayAll(int width)
{
	for (int i = 0; i < GetSize(); i += width)
	{
		for (int j = 0; i + j < GetSize() && j < width; j++)
		{
			std::cout << "\t" << Show(i + j);
		}
		std::cout << "\n";
	}
}

void UList::Add(int newItem)
{
	m_items[tail] = newItem;
	tail++;
}

void UList::BubbleSort()
{
	int store;

	for (int i = 0; i < ULIST_SIZE; i++)
	{
		for (int j = 0; j < ULIST_SIZE - 1; j++)
		{
			if (m_items[i] < m_items[j])
			{
				store = m_items[j];
				m_items[j] = m_items[i];
				m_items[i] = store;
			}
		}
		store = 0;
	}
}

void UList::InsertionSort()
{
	int top;
	int current;
	int temp;

	for (top = 0; top < ULIST_SIZE; top++)
	{
		current = top;

		temp = m_items[current + 1];

		while (current >= 0 && m_items[current] > temp)
		{
			m_items[current + 1] = m_items[current];
			current--;
		}
		m_items[current + 1] = temp;
	}
}

void UList::SelectionSort()
{
	int current;
	int temp;
	int lowestIndex;
	int check;

	for (int i = 0; i < ULIST_SIZE; i++)
	{
		lowestIndex = i;

		for (int j = i; j < ULIST_SIZE; j++)
		{
			if (m_items[j] < m_items[lowestIndex])
			{
				lowestIndex = j;
			}
		}

		temp = m_items[lowestIndex];
		m_items[lowestIndex] = m_items[i];
		m_items[i] = temp;
	}
}