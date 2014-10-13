#include <iostream>
#include <cmath>
#include <set>
#include <cassert>
#include <cstdint>

inline bool isPrime(uint64_t n, std::set<uint64_t> const& primes)
{
	// check if it's a prime number
	bool _isPrime=true;
	for(auto p: primes)
	{
		if(p*p>n || _isPrime==false)
			break;
		if(n % p == 0)
			_isPrime=false;
	}
	return _isPrime;
}

inline std::set<uint64_t> constructPrimes(uint64_t x)
{
	std::set<uint64_t> primes{{2,3,5}};
	for(uint64_t p=2+*primes.rbegin(); p*p<x; p+=2)
	{
		if(isPrime(p,primes))
		{
			primes.insert(p);
		}
	}
	return std::move(primes);
}

inline uint64_t largestPrime(uint64_t x)
{
	std::set<uint64_t> primes(constructPrimes(x));
	uint64_t largest_p =1;
	// Explore the set: {p; p prime and p*p <=x }
	for(auto p: primes)
	{
		if(x %p == 0)
		{
			largest_p=p;
			// reduce x, because: largestPrime(x)=max(p,largestPrime(x/p))
			while(x%p==0)
				x/=p;
		}
	}
	// Explore the set {p; p prime and p*p>x }
	uint64_t p=*primes.rbegin();
	if(x>1)
	{
		// find next prime
		for(uint64_t tmp=x;tmp>p;--tmp)
		{
			if(x % tmp ==0 )
			{
				if(isPrime(x,primes))
				{
					largest_p=tmp;
					break;
				}
			}
		}
	}

	return largest_p;
}

int main(void)
{
	std::cout<< largestPrime(600851475143.0)<<std::endl;
	return 0;
}
