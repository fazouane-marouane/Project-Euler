#include <iostream>
#include <cstdint>
#include <cassert>
// Problem 1:
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.

constexpr inline int32_t sum_1_to_n(int32_t n)
{
	return n*(n+1)/2;
}

// returns the sum of the mutiples of m below x
constexpr inline int32_t sum_multiples(int32_t m, int32_t x)
{
	return m*sum_1_to_n((x-1)/m);
}

// returns the sum of the mutiples of m1 or m2 below x
int32_t sum(int16_t m1, int16_t m2, int32_t x)
{
	assert(m1>0 && m2>0);
	assert(x>=0);
	return sum_multiples(m1,x)+sum_multiples(m2,x)-sum_multiples(m1*m2,x);
}


int main(void)
{
	std::cout<< sum(3,5,1000)<< std::endl;
	return 0;
}
