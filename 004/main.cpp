#include <iostream>
#include <cassert>
#include <cstdint>

constexpr int32_t Pow(int32_t x, int32_t n)
{
	return (n<1? 1
				:(n%2==0?
					 (Pow(x*x,n/2))
					 :(x*Pow(x,n-1))
				 )
			);
}

int32_t digit(int32_t x,int32_t n)
{
	return (x/Pow(10,n))%10;
}

bool isPalindrome(int32_t x)
{
	int32_t largestDigit=10;
	while(largestDigit>0 && digit(x,largestDigit)==0)
	{
		--largestDigit;
	}
	for(int32_t itr=0;itr<=largestDigit/2;++itr)
	{
		if(digit(x,itr)!= digit(x,largestDigit-itr))
			return false;
	}
	return true;
}

int32_t largestPalindrome()
{
	int32_t result=1;
	int32_t b_min=100;
	for(int32_t a=999;a>=b_min;--a)
	{
		for(int32_t b=a;b>=b_min;--b)
		{
			// brute force+ reduce search-space
			if(isPalindrome(a*b) && a*b>result)
			{
				result=a*b;
				b_min=b;
			}
		}
	}
	return result;
}

int main(void)
{
	std::cout<< largestPalindrome() <<std::endl;
	return 0;
}