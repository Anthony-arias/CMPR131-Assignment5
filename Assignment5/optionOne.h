// optionOne.h

#ifndef OPTION_ONE_LOCK
#define OPTION_ONE_LOCK

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "input.h"
#include "Student.h"
using namespace std;

// Functions prototype
void clear(vector<student>& studentVector);
void reserve(vector<student>& studentVector);
void resize(vector<student>& studentVector);
void readFile(vector<student>& studentVector);
void display(vector<student>& studentVector);
void pop_back(vector<student>& studentVector);
void front(vector<student>& studentVector);
void back(vector<student>& studentVector);
void indexUsingSymbol(vector<student>& studentVector);
void begin(vector<student>& studentVector);
void end(vector<student>& studentVector);
void begin_and_end_iterator(vector<student>& studentVector);
void rbegin(vector<student>& studentVector);
void rend(vector<student>& studentVector);
void rbegin_and_rend_iterator(vector<student>& studentVector);
void eraseSingleElement(vector<student>& studentVector);
void eraseWithinRange(vector<student>& studentVector);
void insert(vector<student>& studentVector);
void swap(vector<student>& studentVector);
void sort(vector<student>& studentVector);

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: remove all elements from the vector (which are destroyed)
void clear(vector<student>& studentVector)
{
	studentVector.clear();
	if (studentVector.empty())
		cout << "\n\tVector has been cleared.\n";
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: request that the vector capacity be at least enough to contain n elements
void reserve(vector<student>& studentVector)
{
	int size = inputInteger("\n\tEnter the capacity(1..100): ", 1, 100);
	studentVector.reserve(size);

	if (size == 1)
		cout << "\n\tThe vector has been reserved " << size << " element.\n";
	else
		cout << "\n\tThe vector has been reserved " << size << " elements.\n";
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: resize the container so that it contains n elements
void resize(vector<student>& studentVector)
{
	int size = inputInteger("\tEnter the new size(1..100): ", 1, 100);
	studentVector.resize(size);

	if (size == 1)
		cout << "\n\tThe vector has been resized to " << size << " element.\n";
	else
		cout << "\n\tThe vector has been resized to " << size << " elements.\n";
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: read data from indicated file
void readFile(vector<student>& studentVector)
{
	fstream source;
	string fileName = "input.dat";
	source.open(fileName);
	if (!source)
		cout << "\n\tERROR: Cannot find the file: " << fileName << "\n";
	else
	{
		while (true)
		{
			if (source.fail()) break;
			else
			{
				student temp;
				string line;
				if (getline(source, line, ','))
				{
					temp.setName(line);
					getline(source, line, ',');
					temp.setGradeLevel(line);
					getline(source, line);
					double score = stod(line);
					temp.setGPA(score);
					studentVector.push_back(temp);
				}
			}
		}
		if (studentVector.size() == 1)
			cout << "\n\tThe vector now has " << studentVector.size() << " element.\n\n";
		else
			cout << "\n\tThe vector now has " << studentVector.size() << " elements.\n\n";
		display(studentVector);
	}
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: display the contents in the vector
void display(vector<student>& studentVector)
{
	vector<student>::iterator it;
	if (studentVector.empty())
	{
		cout << "\n\tThe vector is empty.\n";
	}
	else
	{
		int count = 0;
		for (it = studentVector.begin(); it != studentVector.end(); ++it, count++)
			cout << "\t[" << count << "]: " << *it << "\n";
	}
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: remove the last element in the vector
void pop_back(vector<student>& studentVector)
{
	if (studentVector.empty())
		cout << "\n\tThe vector is empty.\n";
	else
	{
		cout << "\n\tElement, [" << studentVector.size() - 1 << "]: " << studentVector.back() << ", has been removed from the list.\n";
		studentVector.pop_back();
		if (studentVector.size() == 1)
			cout << "\n\tThe vector now has " << studentVector.size() << " element.\n";
		else
			cout << "\n\tThe vector now has " << studentVector.size() << " elements.\n";
		display(studentVector);
	}
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: return a reference to the first element in the vector
void front(vector<student>& studentVector)
{
	if (studentVector.empty())
		cout << "\n\tThe vector is empty.\n";
	else
		cout << "\n\tThe element from the front of the vector is [0]: " << studentVector.front() << "\n";
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: return a reference to the last element in the vector
void back(vector<student>& studentVector)
{
	if (studentVector.empty())
		cout << "\n\tThe vector is empty.\n";
	else
		cout << "\n\tThe element from the back of the vector is [" << studentVector.size() - 1 << "]: "<< studentVector.back() << "\n";
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: return a reference to the element at position n in the vector
void indexUsingSymbol(vector<student>& studentVector)
{
	if (studentVector.empty())
		cout << "\n\tThe vector is empty.\n";
	else
	{
		int size = studentVector.size() - 1;
		string tempString = "): ";
		int index = inputInteger("\n\tEnter the index (0.." + to_string(size) + tempString, 0, size);
		cout << "\n\tvector.at(" << index << "): " << studentVector.at(index);
		cout << "\n\tvector[" << index << "]: " << studentVector[index] << "\n";

	}
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: return an iterator pointing to the first element in the vector
void begin(vector<student>& studentVector)
{
	if (studentVector.empty())
		cout << "\n\tThe vector is empty.\n";
	else
	{
		vector<student>::iterator it = studentVector.begin();
		cout << "\n\tThe iterator referring the first element: " << &it << " (" << *it << ")\n";
	}
		
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: return an iterator referring to the past-the-end element in the vector
void end(vector<student>& studentVector)
{
	if (studentVector.empty())
		cout << "\n\tThe vector is empty.\n";
	else
	{
		vector<student>::iterator it = studentVector.end() - 1;
			cout << "\n\tThe iterator referring the past-the-end element: " << &it << " (" << *it << ")\n";
	}
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: using iterator begin() and end() returns all elements in the vector
void begin_and_end_iterator(vector<student>& studentVector)
{
	vector<student>::iterator it;
	if (studentVector.empty())
	{
		cout << "\n\tThe vector is empty.\n";
	}
	else
	{
		int count = 0;
		int index = 1;
		cout << "\n\tUsing begin() and end(), the vector contains:\n";
		for (it = studentVector.begin(); it != studentVector.end(); it++, count++)
			cout << "\t\t[" << count << "]: " << *it << "\n";
	}
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: return a reverse iterator pointing to the last element in the vector
void rbegin(vector<student>& studentVector)
{
	if (studentVector.empty())
	{
		cout << "\n\tThe vector is empty.\n";
	}
	else
	{
		vector<student>::reverse_iterator reverseIt = studentVector.rbegin();
		cout << "\n\tThe reverse iterator pointing to the last element: " << &reverseIt << " (" << *reverseIt << ")\n";
	}
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: return a reverse iterator pointing to the theoretical element preceding the first element in the vector
void rend(vector<student>& studentVector)
{
	if (studentVector.empty())
	{
		cout << "\n\tThe vector is empty.\n";
	}
	else
	{
		vector<student>::reverse_iterator reverseIt = studentVector.rend();
		cout << "\n\tThe reverse iterator pointing to the theoretical element preceding the first element in the vector: " << &reverseIt << " (" << *prev(reverseIt) << ")\n";
	}
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: using iterator rbegin() and rend() returns all elements in the vector
void rbegin_and_rend_iterator(vector<student>& studentVector)
{
	if (studentVector.empty())
	{
		cout << "\n\tThe vector is empty.\n";
	}
	else
	{
		vector<student>::reverse_iterator reverseIt;
		int count = 0;
		cout << "\n\tUsing rbegin() and rend(), the vector contains reversed elements: \n";
		for (reverseIt = studentVector.rbegin(); reverseIt != studentVector.rend(); ++reverseIt, count++)
			cout << "\t\t[" << count << "]: " << *reverseIt << "\n";
	}
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: remove from the vector a single element (using an iterator)
void eraseSingleElement(vector<student>& studentVector)
{
	if (studentVector.empty())
	{
		cout << "\n\tThe vector is empty.\n";
	}
	else
	{
		vector<student>::iterator it1, it2;
		it1 = it2 = studentVector.begin();
		++it1;
		studentVector.erase(it1);
		cout << "\n\tAn element after the begin iterator " << &it2 << " (" << *it2 << ") has been removed.\n";
	}
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: remove from the vector a range of elements(using iterators)
void eraseWithinRange(vector<student>& studentVector)
{
	if (studentVector.empty())
		cout << "\n\tThe vector is empty.\n";
	else
	{
		vector<student>::iterator it1, it2;
		student s1, s2;
		it1 = studentVector.begin();
		s1 = studentVector.front();
		it2 = studentVector.end();
		s2 = studentVector.back();
		studentVector.erase(it1, it2);
		cout << "\n\tAll elements starting at begin iterator " << &s1 << " (" << s1 << ") ";
		cout << "\n\tand going up to end iterator " << &s2 << " (" << s2 << ") has been removed.\n";
	}
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: insert a new entry at the iterator
void insert(vector<student>& studentVector)
{
	vector<student>::iterator it;
	student s;
	it = studentVector.begin();
	if (!studentVector.empty())
		++it;
	s.setName(inputString("\n\tEnter a new student name: ", true));
	int grade = inputInteger("\n\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);
	string gradeLevel[4] = { "Freshman","Sophmore","Junior","Senior" };
	s.setGradeLevel(gradeLevel[grade - 1]);
	s.setGPA(inputDouble("\n\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0));
	studentVector.insert(it, s);
	cout << "\n\tThe new element has been inserted after the begin iterator.\n";
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: exchange the content of the container by another vector's content of the same type
void swap(vector<student>& studentVector)
{
	vector<student> temp;
	cout << "\n\tVector (temp) is initially empty.\n";
	studentVector.swap(temp);
	if (studentVector.empty())
	{
		cout << "\n\tVector (studentVector) is empty after swapped with vector (temp).\n";
		if (temp.size() == 1)
			cout << "\n\tVector (temp) now has " << temp.size() << " element:\n";
		else
			cout << "\n\tVector (temp) now has " << temp.size() << " elements:\n";
	}

	display(temp);
}

// Precondition: a valid reference of vector with indicated class and objects
// Postcondition: sort the vector
void sort(vector<student>& studentVector)
{
	sort(studentVector.begin(), studentVector.end());
	display(studentVector);
}

#endif
