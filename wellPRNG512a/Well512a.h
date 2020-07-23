#pragma once
#include <stdint.h>
#include <vector>
#include "SplitMix.h"
class Well512a
{

public:

	typedef unsigned long long result_type;
	static constexpr result_type min() { return 0; }
	static constexpr result_type max() { return ULLONG_MAX; }
	result_type operator()() { return randGen(); }



	Well512a();
	~Well512a();

	void setSeed(uint32_t);
	double randGen();
};

