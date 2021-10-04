// optionTwo.h

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK
#include <fstream>
#include "Student.h"
#include "input.h"
#include<sstream>
#include <list>


using namespace std;

//push_front(e) - Adds a new element at the front of the list
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

//push_back(e) - Adds a new element at the end of the list
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

//Read input.datand push_front(e) - Adds a new element at the front of the list
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
       
        cout << "\n\t\tThe list now has " << studentList.size() << " elements." << endl;
    }

}

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

//Destroys all elements from the list
void destroyList(list<student>& studentList)
{
    studentList.clear();
    if (studentList.empty())
        cout << "\n\t\tThe list has been cleared." << endl;
}

//Changes the list so that it contains n elements
void resize(list<student>& studentList)
{
    int size = inputInteger("\n\t\tEnter the new size(1..100): ", 0, 100);
    studentList.resize(size);
    cout << "\n\t\tThe list has been resized to " << studentList.size() << " elements" << endl;
}

//pop_front() - Deletes the first element
void deleteFirst(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        cout << "\n\t\tFirst element,(" << studentList.front() << "), has been removed from the list." << endl;
        studentList.pop_front();
        cout << "\n\t\tThe list now has " << studentList.size() << " elements." << endl;
        display(studentList);
    }
}

//pop_back() - Delete the last element
void deleteLast(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        cout << "\n\t\tLast element,(" << studentList.back() << "), has been removed from the list." << endl;
        studentList.pop_back();
        cout << "\n\t\tThe list now has " << studentList.size() << " elements." << endl;
        display(studentList);
    }
}

//front() - Accesses the first element
void accessFirst(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
        cout << "\n\t\tFirst element from the list is (" << studentList.front() << ")." << endl;

}
//back() Accesses the last element
void accessBack(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
        cout << "\n\t\tLast element from the list is (" << studentList.back() << ")." << endl;

}

//begin() - Returns an iterator refereing to the first element in the list
void firstIt(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::iterator it = studentList.begin();
        cout << "\n\t\tThe iterator referring the first element: (" << *it << ")." << endl;
    }

}

//end() Returns an iterator referring to the past-the-end element in the list
void lastIt(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::iterator it = studentList.end();
        cout << "\n\t\tThe iterator referring to the past-the-end element: (" << *prev(it) << ")." << endl;
    }

}

//Using iterator begin() and end() returns all elements in the list
void beginEndIterator(list<student>& studentList)
{
    
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::iterator it;
        cout << "\n\t\tUsing begin() and end(), the list contains: \n" << endl;
        for (it = studentList.begin(); it != studentList.end(); ++it)
            cout << "\t\t" << *it << endl;
    }
}

//rbegin() - Returns a reverse iterator pointing to the last element in the list
void reverseFirstElement(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::reverse_iterator rit = studentList.rbegin();
        cout << "\n\t\tThe iterator referring the reverse first element: (" << *rit << ")." << endl;
    }

}

//rend() - Returns a reverse iterator pointing to the element preceding the first element
void reverseLastElement(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::reverse_iterator rit = studentList.rend();
        cout << "\n\t\tThe iterator referring to the reverse past-the-end element: (" << *prev(rit) << ")." << endl;
    }

}

//Using iterator rbegin() and rend() returns all elements in the list
void rbeginRendIterator(list<student>& studentList)
{


    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::reverse_iterator rit;
        cout << "\n\t\tUsing rbegin() and rend(), the list contains: \n" << endl;
        for (rit = studentList.rbegin(); rit != studentList.rend(); ++rit)
            cout << "\t\t" << *rit << endl;
    }
}

//erase(it) - Removes from the list a single element(using an iterator)
void removeUsingIterator(list<student>& studentList)
{
    if (studentList.empty())
        cout << "\n\t\tThe list is empty." << endl;
    else
    {
        list<student>::iterator it1, it2;
        it1 = it2 = studentList.begin();
        ++it1;
        studentList.erase(it1);
        cout << "\n\t\tAn element after the begin iterator (" << *it2 << ") has been removed."<< endl;
    }
}

//erase(start_it,end_it) - Removes from the list a range of elements( using iterators)
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

//insert(it, entry) - Insert a new entry at the iterator.
void insertAfterIterators(list<student>& studentList)
{
    list<student>::iterator it;
    student s;
    it = studentList.begin();
    ++it;
    s.setName(inputString("\n\t\tEnter a new student name: ", true));
    int grade = inputInteger("\n\t\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);
    string gradeLevel[4] = { "Freshman","Sophmore","Junior","Senior"};
    s.setGradeLevel(gradeLevel[grade - 1]);
    s.setGPA(inputDouble("\n\t\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0));
    studentList.insert(it, s);
    cout << "\n\t\tThe new element has been inserted after the begin iterator." << endl;

}
#endif