#include "stdafx.h"

#include<iostream>
#include<ctime>
#include "UList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// Variables to calculate how long it took
	unsigned int start, duration;

	// Seed the random number generator
	srand((unsigned int)time(NULL));

	// Create a new list object
	UList testlist;

	// Fill it with random values
	while (!testlist.IsFull())
		testlist.Add(rand() % ULIST_SIZE / 2);

	// Show everything in the unsorted list
	std::cout << "\nRandom data generated:\n";
	testlist.DisplayAll(8);

	// Perform the sort, and time it.
	std::cout << "\nSorting...";
	start = clock();
	testlist.SelectionSort();
	//testlist.InsertionSort();
	//testlist.BubbleSort();
	duration = clock() - start;
	std::cout << "Sorted in: " << duration << "ms\n";

	// Show the sorted list
	testlist.DisplayAll(8);

	std::cin.get();
	return 0;
}

