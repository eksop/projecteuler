#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 6008514751431UL

unsigned long int check_prime(unsigned long int);

int main()
{
  unsigned long int sr, flag = 1;
	clock_t begin, end;
	double time_spent;
	
	begin = clock();
	sr = ((unsigned long int)sqrt(N)) + 1;
	
	while((sr > 1) && (flag))
	{
		if (check_prime(sr))
		{	
			if(!(N % sr))
				flag = 0UL;
		}
			sr--;
	}
	
	printf("\nLargest Prime Factor is %u", sr + 1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n%g",time_spent);
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
