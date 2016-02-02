#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define N 1000000

unsigned long int collatz(unsigned long long int n);

int main()
{
	int i, l_no, l_seq, cur, n, flag = 0;
	
	l_no = 1;
	l_seq = 1;
	
	for(i = N - 1; i > 1; i--)
	{
		cur = collatz( i );
		if(l_seq < cur)
		{
			l_seq = cur;
			l_no = i;
		}
	}
	
	printf("\nLargest collatz sequence gerating no : %d and no in seq %d", l_no, l_seq);

	return 0;
}

unsigned long int collatz(unsigned long long int n) 
{
	unsigned long int count = 0;

	for(;;)
	{
		if(n == 1)
		{
			count++;
			return count;
		}
		else
		{
			if( !(n % 2) )
			{
				count++;
				n = n / 2;
			}
			else
			{
				count++;
				n = 3 * n + 1;
			}
		}
	}
}
