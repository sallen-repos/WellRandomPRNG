#include "pch.h"
#include "Well512a.h"
#include <limits>
#include <array>

//xor then shift-left
#define XSL(shift, value) (value ^ (value << shift))
//xor then shift-right
#define XSR(shift, value) (value ^ (value >> shift))
//xor then shift-left then apply mask
#define XSLM(shift,mask,value) (value ^ ((value << shift) & mask)) 

//mask that leaves only the Least Significant Bit (LSB) when using a bitwise and ( x & mask = LSB of x)
const uint32_t LSB_MASK = 0x0fU;

const uint32_t STATE_SIZE = 32;
static uint32_t state[STATE_SIZE];
static uint32_t stateIndex = 0;
static uint32_t z0, z1, z2;

Well512a::Well512a()
{
}


Well512a::~Well512a()
{
}

//using split mix to seed initial state
void Well512a::setSeed(uint32_t input) {

	Splitmix splitmix;
	splitmix.setSeed(input);

	int j;
	stateIndex = 0;
	for (j = 0; j < STATE_SIZE; j++)
		state[j] = splitmix.splitmix();
}

double Well512a::randGen() {  

	z0 = state[(stateIndex + 15) & LSB_MASK];
	z1 = XSL(16, state[stateIndex]) ^ XSL(15, state[(stateIndex + 13) & LSB_MASK]);
	z2 = XSR(11, state[(stateIndex + 9) & LSB_MASK]);
	state[stateIndex] = z1 ^ z2;
	uint32_t temp = XSLM(5, 0xda442d24U, state[stateIndex]);
	stateIndex = (stateIndex + STATE_SIZE - 1) & LSB_MASK;
	state[stateIndex] = XSL(2, z0) ^ XSL(18, z1) ^ (z2 << 28) ^ temp;

	return state[stateIndex];
		
}
