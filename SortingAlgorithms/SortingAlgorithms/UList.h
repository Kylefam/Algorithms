#pragma once
#define ULIST_SIZE 1999

class UList
{
private:
	int m_items[ULIST_SIZE];
	int tail;

public:
	UList(void);

	// Return true if the list is empty
	bool IsEmpty();

	// Return true if the list is full
	bool IsFull();

	// Return the number of elements in the list
	int GetSize();

	// Return the data in the list at element "idx"
	int Show(int idx);

	// Show everything currently in the list in a block of "width" columns
	void DisplayAll(int width);

	// Add an element to the list (unsorted)
	void Add(int newItem);

	// Perform a bubblesort on the list
	void BubbleSort();

	// Perform a insertionsort on the list
	void InsertionSort();

	// Perform a selectionsort on the list
	void SelectionSort();
};
