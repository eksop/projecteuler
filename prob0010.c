#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define N 2000000LL

unsigned long int check_prime(unsigned long int);

int main()
{
	unsigned long long int i, c = 0, sum = 0;
	
	for(i = 1; i <= 2000000LL; i++)
	{	
		if(check_prime(i))
		{
			c += 1;
			sum += i;
		}
	}
	
	printf("\nSum = %llu, count = %llu, i = %llu", sum, c, i);
	return 0;
}

/*
unsigned long int check_prime(unsigned long int a)
{
	unsigned long int i ,s , flag = 0;
	if(a == 0 || a == 1)
		return 0;
	else
	{
		if( !(a % 2) )
		{	
			if(a == 2)
				return 1;
			else
				return 0;
		}
		else
		{
			for ( i = 3 ; i <= a ; i += 1 )
			{ 
				if ( a % i == 0 )
				{
					flag++;
					if(flag > 1)
						return 0;
				}
			}
		}
		return 1;
	}
}*/


unsigned long int check_prime(unsigned long int a)
{
	unsigned long int i ,s , flag = 0;
	if(a == 0 || a == 1)
		return 0;
	else
	{
		if( !(a % 2) )
		{	
			if(a == 2)
				return 1;
			else
				return 0;
		}
		else
		{
			s = ((unsigned long int)sqrt(a)) + 1;
			for ( i = 1 ; i <= s ; i += 2 )
			{ 
				if ( a % i == 0 )
				{
					flag++;
					if(flag > 1)
						return 0;
				}
			}
		}
		
		return 1;
	}
}