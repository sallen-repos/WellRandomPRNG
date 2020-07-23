#include "pch.h"
#include "Splitmix.h"


static uint32_t seedValue;

Splitmix::Splitmix()
{
}


Splitmix::~Splitmix()
{
}

// Seeds Splitmix with input
void Splitmix::setSeed(uint32_t input)
{
	seedVal = input;
}

// Generates a Random number from seed with 64 bits of state
uint32_t Splitmix::splitmix()
{
	result = (seedVal += 0x9e3779b97f4a7c15);
	result = (result ^ (result >> 30)) * 0xbf58476d1ce4e5b9;
	result = (result ^ (result >> 27)) * 0x94d049bb133111eb;
	result ^ (result >> 31);
	seedVal += result;

	return result;
}
