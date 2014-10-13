#include <iostream>
#include <cassert>
#include <cstdint>
#include <cmath>

// Problem 2:
// Find the sum of the even-valued terms whose values do not exceed four million

constexpr double goldenratio=(1+sqrt(5))/2;

constexpr inline int32_t find_maximal_n_helper(int32_t x)
{
	return std::floor(std::log(x*std::sqrt(5))/std::log(goldenratio));
}

constexpr inline int32_t find_maximal_n(int32_t x)
{
	return (find_maximal_n_helper(x)/3)*3;
}

constexpr inline int32_t Fibonacci(int32_t n)
{
	return (std::pow(goldenratio,n)-std::pow(1-goldenratio,n))/std::sqrt(5);
}

constexpr inline int32_t sum_even_Fibonacci(int32_t x)
{
	return (Fibonacci(find_maximal_n(x)+2)-Fibonacci(2))/2;
}

int main(void)
{
	int32_t max= 4000000;
	std::cout<< sum_even_Fibonacci(max)<<std::endl;
	return 0;
}