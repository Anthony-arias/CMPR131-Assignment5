// optionThree.h

#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK

#include <list>
#include <iostream>
#include <string>
#include "input.h"

//PreCondition: input is type list<int>
//PostCondition: add integer to list
void addInteger(std::list<int> &intList)
{
	int input = inputInteger("\n\t\tAdd an integer: ");
	intList.push_back(input);
}

//PreCondition: input is type list<int>
//PostCondition: delete integer from list
void deleteIneger(std::list<int>& intList)
{
	int sizeBeforeDelete = intList.size();
	int input = inputInteger("\n\t\tDelete an integer: ");
	intList.remove(input);
	if (intList.size() == sizeBeforeDelete) std::cout << "\n\t\tlist does not contain: " + std::to_string(input) + "." << std::endl;

}

//PreCondition: input is type list<int>
//PostCondition: display elements in list
void displayIntList(std::list<int> intList)
{
	std::cout << "\n\t\tcontainer: ";
	if (intList.size() == 0) std::cout << "empty";
	for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

//PreCondition: input is type list<int>
//PostCondition: display frequencies of elements in list
void displayFrequencies(std::list<int> intList)
{
	if (intList.size() == 0)
	{
		std::cout << "\n\t\tcontainer: empty" << std::endl;
		return;
	}
	std::list<int> sortedTemp = intList;
	sortedTemp.sort();
	
	int thisNumb = *sortedTemp.begin();
	int counter = 0;

	std::cout << "\n\t\tcontainer:";
	for (std::list<int>::iterator it = sortedTemp.begin(); it != sortedTemp.end(); it++)
	{	
		if (thisNumb == *it)
		{
			counter++;
		}
		else if (thisNumb != *it)
		{
			std::cout << "\n\t\t" << thisNumb << ": " << counter;
			thisNumb = *it;
			counter = 1;
		}
	}
	std::cout << "\n\t\t" << sortedTemp.back() << ": " << counter;
	std::cout << std::endl;
}

#endif