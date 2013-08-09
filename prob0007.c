#include <stdio.h>
#include <math.h>

#define RANGE 10001

unsigned long int check_prime(unsigned long int);

int main()
{
	unsigned long int prime = 1, i ,j ;
	
	for(i = 1; i <= RANGE; i++)
	{
		j = prime;
		j++;
		while( !check_prime(j) )
			j++;
		prime = j;
	}
	
	printf("\n%d prime is %u", RANGE, prime);
	return 0;
}	

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