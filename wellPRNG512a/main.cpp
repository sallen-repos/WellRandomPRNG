// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Well512a.h"
#include <vector>
#include <random>

std::uniform_int_distribution<> dist{ 1, 50 };

#define myDist(value) dist(value)

int main()
{	
	Well512a wellRandom;

	
	
	

	wellRandom.setSeed(54564564);

	uint32_t rand = wellRandom.randGen();

	std::cout << rand;

	
	
	std::uniform_int_distribution<> dist{ 1, 50 };

	//std::uniform_real_distribution<> dist{ 0.0, 0.5 };

	for (int i = 0; i != 100; ++i)
	{
	std::cout << myDist(wellRandom) << std::endl;
	}	

	system("pause");

	return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
