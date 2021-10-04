// menus.h

#include <iostream>
#include <string>

using namespace std;

//PreCondition: NA
//PostCondition: displays main menu options
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter 5: Vector and List Container by Anthony, An, Van, Vincent, Nhan (10/7/21)" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\t1> Vector container" << endl;
    cout << "\t\t2> List container" << endl;
    cout << "\t\t3> Application using Vector and/or List container" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option one menu options
void displayOptionOneMenu(void)
{
    cout << "\n\tVectors are sequence containers representing arrays that can change in size." << endl;
    cout << "\n\t1> Vector's member functions" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\tA> clear() - Removes all elements from the vector (which are destroyed)" << endl;
    cout << "\t\tB> reserve(n) - Requests that the vector capacity be at least enough to contain n elements" << endl;
    cout << "\t\tC> resize(n) - Resizes the container so that it contains n elements" << endl;
    cout << "\t\tD> Read input.dat and push_back(e) - Adds a new element at the end of the vector" << endl;
    cout << "\t\tE> pop_back() - Removes the last element in the vector" << endl;
    cout << "\t\tF> front() - Returns a reference to the first element in the vector" << endl;
    cout << "\t\tG> back() - Returns a reference to the last element in the vector" << endl;
    cout << "\t\tH> index using at() or []) - Returns a reference to the element at position n in the vector" << endl;
    cout << "\t\tI> begin() - Returns an iterator pointing to the first element in the vector" << endl;
    cout << "\t\tJ> end() Returns an iterator referring to the past-the-end element in the vector" << endl;
    cout << "\t\tK> Using iterator begin() and end() returns all elements in the vector" << endl;
    cout << "\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the vector" << endl;
    cout << "\t\tM> rend() - Returns a reverse iterator pointing to the theoretical element preceding the first" << endl;
    cout << "\t\t\telement in the vector" << endl;
    cout << "\t\tN> Using iterator rbegin() and rend() returns all elements in the vector" << endl;
    cout << "\t\tO> erase(it) - Removes from the vector a single element(using an iterator)" << endl;
    cout << "\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)" << endl;
    cout << "\t\tQ> insert(it, entry) - Insert a new entry at the iterator." << endl;
    cout << "\t\tR> swap() - Exchanges the content of the container by another vector's content of the same type" << endl;
    cout << "\t\tS> Sort - Sorts the vector." << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option two menu options
void displayOptionTwoMenu(void)
{
    cout << "\n\t2> List container" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\tA> clear() - Destroys all elements from the list" << endl;
    cout << "\t\tB> resize(n) - Changes the list so that it contains n elements" << endl;
    cout << "\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list" << endl;
    cout << "\t\tD> pop_front() - Deletes the first element" << endl;
    cout << "\t\tE> front() - Accesses the first element" << endl;
    cout << "\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list" << endl;
    cout << "\t\tG> pop_back() - Delete the last element" << endl;
    cout << "\t\tH> back() Accesses the last element" << endl;
    cout << "\t\tI> begin() - Returns an iterator refereing to the first element in the list" << endl;
    cout << "\t\tJ> end() Returns an iterator referring to the past-the-end element in the list" << endl;
    cout << "\t\tK> Using iterator begin() and end() returns all elements in the list" << endl;
    cout << "\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list" << endl;
    cout << "\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element" << endl;
    cout << "\t\t\tin the list" << endl;
    cout << "\t\tN> Using iterator rbegin() and rend() returns all elements in the list" << endl;
    cout << "\t\tO> erase(it) - Removes from the vector a single element(using an iterator)" << endl;
    cout << "\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)" << endl;
    cout << "\t\tQ> insert(it, entry) - Insert a new entry at the iterator." << endl;
    cout << "\t\tR> swap() - Exchanges the content of the container by another list's content of the same type" << endl;
    cout << "\t\tS> Sort - Sorts the list." << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option three menu options
void displayOptionThreeMenu(void)
{
    cout << "\n\t3> Application using Vector and/or List container" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\tA> Add an integer" << endl;
    cout << "\t\tB> Delete an integer" << endl;
    cout << "\t\tC> Display input integers" << endl;
    cout << "\t\tD> Display frequencies of integers" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}
