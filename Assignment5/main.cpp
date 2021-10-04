// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 5: 
// 10/7/2021

#include <iostream>
#include <string>
#include "optionOne.h"
#include "optionTwo.h"
#include "optionThree.h"
#include "input.h"
#include "menus.h"
#include <list>
#include<iomanip>


void mainMenu(void);
void programOne(void);
void programTwo(void);
void programThree(void);

using namespace std;

int main(void)
{
    mainMenu();
    return 0;
}

//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{
    do
    {
        clearScreen();

        displayMainMenu();

        int userInput = inputInteger("\t\tOption: ", 0, 3);
        switch (userInput)
        {
        case 0: clearScreen(); return;
        case 1: clearScreen(); programOne(); break;
        case 2: clearScreen(); programTwo(); break;
        case 3: clearScreen(); programThree(); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..3." << endl;
        }

    } while (true);
}

//PreCondition: NA
//PostCondition:
void programOne(void)
{
    do
    {
        clearScreen();
        displayOptionOneMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': /*Function here*/ pause("\n\t\tPress enter to continue..."); break;
        case 'b': case 'B': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'c': case 'C': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'd': case 'D': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'e': case 'E': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'f': case 'F': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'g': case 'G': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'h': case 'H': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'i': case 'I': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'j': case 'J': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'k': case 'K': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'l': case 'L': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'm': case 'M': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'n': case 'N': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'o': case 'O': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'p': case 'P': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'q': case 'Q': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'r': case 'R': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 's': case 'S': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R', or 'S'" << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}


//PreCondition: NA
//PostCondition:
void programTwo(void)
{
    list<student> studentList;
    clearScreen();
    cout << "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the";
    cout << "\n\tsequence, and iteration in both directions." << endl;
    do
    {

        displayOptionTwoMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': destroyList(studentList); break;
        case 'b': case 'B': resize(studentList); break;
        case 'c': case 'C': readfile(studentList, option); break;
        case 'd': case 'D': deleteFirst(studentList); break;
        case 'e': case 'E': accessFirst(studentList); break;
        case 'f': case 'F': readfile(studentList, option); break;
        case 'g': case 'G': deleteLast(studentList); break;
        case 'h': case 'H': accessBack(studentList); break;
        case 'i': case 'I': firstIt(studentList); break;
        case 'j': case 'J': lastIt(studentList);  break;
        case 'k': case 'K': beginEndIterator(studentList);  break;
        case 'l': case 'L': reverseFirstElement(studentList);  break;
        case 'm': case 'M': reverseLastElement(studentList);  break;
        case 'n': case 'N': rbeginRendIterator(studentList);  break;
        case 'o': case 'O': removeUsingIterator(studentList);  break;
        case 'p': case 'P': removeAllUsingIterators(studentList);  break;
        case 'q': case 'Q': insertAfterIterators(studentList);  break;
        case 'r': case 'R': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 's': case 'S':  display(studentList); pause("\n\t\tPress enter to continue...");  break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R', or 'S'" << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}

//PreCondition: NA
//PostCondition:
void programThree(void)
{
    do
    {
        clearScreen();
        displayOptionThreeMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': /*Function here*/ pause("\n\t\tPress enter to continue..."); break;
        case 'b': case 'B': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'c': case 'C': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'd': case 'D': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C', or 'D'" << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}