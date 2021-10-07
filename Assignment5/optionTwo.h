// optionTwo.h

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK
#include <fstream>
#include "Student.h"
#include "input.h"
#include<sstream>
#include <list>


using namespace std;
//PreCondition: input source file, student, and studentList
//PostCondition: Adds a new element at the front of the list
void pushfront(fstream& source, student& s, list<student> & studentList)
{
    string line;
    if (getline(source, line,','))
    {
        s.setName(line);
        getline(source, line, ',');
        s.setGradeLevel(line);
        getline(source, line);
        double score = stod(line);
        s.setGPA(score);
        studentList.push_front(s);
    }
}

//PreCondition: input source file, student, and studentList
//PostCondition: Adds a new element at the end of the list
void pushback(fstream& source, student& s, list<student>& studentList)
{
    string line;
    if (getline(source, line, ','))
    {
        s.setName(line);
        getline(source, line, ',');
        s.setGradeLevel(line);
        getline(source, line);
        double score = stod(line);
        s.setGPA(score);
        studentList.push_back(s);
    }
}

//PreCondition: input studentList and option 
//PostCondition: Read data from the input.dat file.
//If the option is C -  Adds a new element at the front of the list else adds a new element at the end of the list
void readfile(list<student>& studentList, char option)
{

    fstream source;
    string fileName = "input.dat";
    source.open(fileName);
    if (!source)
        cout << "\n\t\tERROR: Cannot find the file: " << fileName << endl;
    else
    {
        while (true)
        {
            if (source.fail()) break; // not "failure", just end of file
            else
            {
                student newStudent;
                if(option =='C')
                    pushfront(source, newStudent, studentList);
                else
                    pushback(source, newStudent, studentList);
            }
        }
        source.close();
        if (studentList.size() == 1)
            cout << "\n\t\tThe list now has " << studentList.size() << " element." << endl;
        else
            cout << "\n\t\tThe list now has " << studentList.size() << " elements." << endl;
    }

}

//PreCondition: input studentList 
//PostCondition: Display all elements from the list on the screen.
void display(list<student>& studentList)
{
  
    list<student>::iterator it;
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        cout << endl;
        for (it = studentList.begin(); it != studentList.end(); ++it)
            cout << "\t\t" << *it << endl;
    }
}

//PreCondition: input studentList 
//PostCondition: Destroys all elements from the list
void destroyList(list<student>& studentList)
{
    studentList.clear();
    if (studentList.empty())
        cout << "\n\t\tThe list has been cleared." << endl;
}

//PreCondition: input studentList 
//PostCondition: Changes the list so that it contains n elements
void resize(list<student>& studentList)
{
    int size = inputInteger("\n\t\tEnter the new size(1..100): ", 0, 100);
    studentList.resize(size);
    if (studentList.size() == 1)
        cout << "\n\t\tThe list has been resized to " << studentList.size() << " element." << endl;
    else
        cout << "\n\t\tThe list has been resized to " << studentList.size() << " elements." << endl;
}

//PreCondition: input studentList 
//PostCondition: Deletes the first element
void deleteFirst(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        cout << "\n\t\tFirst element,(" << studentList.front() << "), has been removed from the list." << endl;
        studentList.pop_front();
        if (studentList.size() == 1)
            cout << "\n\t\tThe list now has " << studentList.size() << " element." << endl;
        else
            cout << "\n\t\tThe list now has " << studentList.size() << " elements." << endl;
        display(studentList);
    }
}

//PreCondition: input studentList 
//PostCondition: Delete the last element
void deleteLast(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        cout << "\n\t\tLast element,(" << studentList.back() << "), has been removed from the list." << endl;
        studentList.pop_back();
        if (studentList.size() == 1)
            cout << "\n\t\tThe list now has " << studentList.size() << " element." << endl;
        else
            cout << "\n\t\tThe list now has " << studentList.size() << " elements." << endl;
        display(studentList);
    }
}

//PreCondition: input studentList 
//PostCondition: Show the first element
void accessFirst(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
        cout << "\n\t\tFirst element from the list is (" << studentList.front() << ")." << endl;

}
//PreCondition: input studentList 
//PostCondition: Show the last element
void accessBack(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
        cout << "\n\t\tLast element from the list is (" << studentList.back() << ")." << endl;

}

//PreCondition: input studentList 
//PostCondition: Show an iterator refereing to the first element in the list
void firstIt(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::iterator it = studentList.begin();
        cout << "\n\t\tThe iterator referring the first element: " << &it << "." << endl;
    }

}


//PreCondition: input studentList 
//PostCondition: Show an iterator referring to the past-the-end element in the list
void lastIt(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::iterator it = studentList.end();
        cout << "\n\t\tThe iterator referring to the past-the-end element: " << &it << "." << endl;
    }

}

//PreCondition: input studentList 
//PostCondition: Using iterator begin() and end() returns all elements in the list
void beginEndIterator(list<student>& studentList)
{
    
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::iterator it;
        cout << "\n\t\tUsing begin() and end(), the list contains: \n" << endl;
        for (it = studentList.begin(); it != studentList.end(); it++)
            cout << "\t\t" << &it << " (" << *it << ") " << endl;
    }
}

//PreCondition: input studentList 
//PostCondition: Show a reverse iterator pointing to the last element in the list
void reverseFirstElement(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::reverse_iterator rit = studentList.rbegin();
        cout << "\n\t\tThe iterator referring the reverse first element: " << &rit << "." << endl;
    }

}

//PreCondition: input studentList 
//PostCondition: Show a reverse iterator pointing to the element preceding the first element
void reverseLastElement(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::reverse_iterator rit = studentList.rend();
        cout << "\n\t\tThe iterator referring to the reverse past-the-end element: " << &rit << "." << endl;
    }

}

//PreCondition: input studentList 
//PostCondition: Using iterator rbegin() and rend() returns all elements in the list
void rbeginRendIterator(list<student>& studentList)
{

    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::reverse_iterator rit;
        cout << "\n\t\tUsing rbegin() and rend(), the list contains: \n" << endl;
        for (rit = studentList.rbegin(); rit != studentList.rend(); ++rit)
            cout << "\t\t" << &rit << " (" << *rit << ") " << endl;
    }
}

//PreCondition: input studentList 
//PostCondition: Removes from the list a single element(using an iterator)
void removeUsingIterator(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::iterator it1, it2;
        it1 = it2 = studentList.begin();
        if (studentList.size() == 1)
        {
            studentList.erase(it1);
            cout << "\n\t\tAn element has been removed. The list is empty." << endl;
        }
        else
        {
            ++it1;
            studentList.erase(it1);
            cout << "\n\t\tAn element after the begin iterator" << &it2 << " (" << *it2 << ") has been removed." << endl;
        }
    }
}

//PreCondition: input studentList 
//PostCondition: Removes from the list a range of elements( using iterators)
void removeAllUsingIterators(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::iterator it1, it2;
        student s1, s2;
        it1 = studentList.begin();
        s1 = studentList.front();
        it2 = studentList.end();
        s2 = studentList.back();
        studentList.erase(it1, it2);
        cout << "\n\t\tAll elements starting at begin iterator (" << s1 << ") \n\t\tand going up to end iterator (" 
            << s2 << ") has been removed." << endl;
    }
}


//PreCondition: input studentList 
//PostCondition: Insert a new entry at the iterator.
void insertAfterIterators(list<student>& studentList)
{
    list<student>::iterator it;
    student s;
    s.setName(inputString("\n\t\tEnter a new student name: ", true));
    int grade = inputInteger("\n\t\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);
    string gradeLevel[4] = { "Freshman","Sophmore","Junior","Senior"};
    s.setGradeLevel(gradeLevel[grade - 1]);
    s.setGPA(inputDouble("\n\t\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0));
    it = studentList.begin();
    if (studentList.empty())
    {
        studentList.insert(it, s);
        cout << "\n\t\tThe new element has been inserted into the list." << endl;
    }
    else
    {
        ++it;
        studentList.insert(it, s);
        cout << "\n\t\tThe new element has been inserted after the begin iterator." << endl;
    }

}

//PreCondition: input studentList 
//PostCondition: Exchanges the content of the container by another list's content of the same type
void swapTwoLists(list<student>& l1)
{
    list<student> l2;   
    cout << "\n\t\tList (l2) is initially empty." << endl;
    l1.swap(l2);
    if(l1.empty())
        cout << "\n\t\tList (l1) is empty after swapped with list (l2)." << endl;
    else
    {
        if (l2.size() == 1)
            cout << "\n\t\tList (l2) now has " << l2.size() << " element:" << endl;
        else
            cout << "\n\t\tList (l2) now has " << l2.size() << " elements:" << endl;
    }
    display(l2);

}

//PreCondition: input studentList 
//PostCondition: Sorts the list.
void sortList(list<student>& studentList)
{

    studentList.sort();

    display(studentList);

}

#endif