#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List list;
	struct List::list my_list;
	list.init(&my_list);

	while (true)
	{
		string input = " ";

		int numInput;

		int flush;

		cout << "\n\nStudent Struct Ordered List Test\n -------------------------\n\n\n";

		cout << "Select an option:\n\n a - Add an value to the List\n r - Remove a value from the List\n f - Display the list\n x - Exit the program\n\n";

		cin >> input;

		if (input == "a")
		{
			Student temp;
			cout << "\n\nEnter the students ID ";
			cin >> numInput;
			temp.id = numInput;
			cout << "\n\nEnter the students Name ";
			cin >> input;
			temp.name = input;
			cout << "\n\nEnter the students Age ";
			cin >> numInput;
			temp.age = numInput;

			list.add(&my_list, temp);
		}
		else if (input == "r")
		{
			cout << "Enter the student id you want to remove from the list\n";
			cin >> numInput;

			int check = list.search(&my_list, numInput);

			if (check != -1)
			{
				list.remove(&my_list, numInput);
				cout << "Studen with the ID "<< numInput << " Was removed from the list" << endl;
			}
			else
			{
				cout << "That number wasnt found in the list of student ids";
			}
		}
		if (input == "f")
		{
			list.showlist(my_list);
		}
		else if (input == "x")
		{
			cout << "Goodbye";
			exit(0);
		}
	}
}