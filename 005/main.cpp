#include <iostream>
#include <set>
#include <cassert>
#include <cstdint>

bool isPrime(int32_t n,std::set<int32_t> const& primes)
{
	bool _isPrime= true;
	for(auto p: primes)
	{
		if(p*p>n || _isPrime==false)
			break;
		if(n%p==0)
			_isPrime=false;
	}
	return _isPrime;
}

int32_t nextPrime(std::set<int32_t> const& primes)
{
	for(int32_t tmp= 2+ *primes.rbegin();;tmp+=2)
	{
		if(isPrime(tmp,primes))
		{
			return tmp;
		}
	}
}

int32_t evenlyDivisible(int32_t x)
{
	std::set<int32_t> primes ={{2,3}};
	int32_t p;
	while((p=nextPrime(primes))<=x)
		primes.insert(p);
	int32_t result=1;
	for(auto p: primes)
	{
		int32_t tmp=p;
		while(tmp*p<x)
			tmp*=p;
		result*=tmp;
	}
	return result;
}

int main(void)
{
	std::cout<< evenlyDivisible(20) <<std::endl;
	return 0;
}