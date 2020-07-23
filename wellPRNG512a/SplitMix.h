#pragma once
#include <stdint.h>
class Splitmix
{

private:

	uint32_t seedVal;
	uint32_t result;

public:
	Splitmix();
	~Splitmix();


	void setSeed(uint32_t);
	uint32_t splitmix();




};

