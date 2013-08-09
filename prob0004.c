#include <stdio.h>
#include <math.h>
#include <time.h>

#define SIZE 100

int check_palindrome(unsigned long int);

int main()
{
  clock_t begin, end;
		
	double time_spent;

	begin = clock();
	
	unsigned long int m, n, flag = 0, largest;
	
	for(m = 999; m > 99; m--)
	{
		for(n = 999; n > 99; n--)
		{
			if(check_palindrome(m * n))
			{
				if(!flag)
				{
					largest = m * n;
					flag = 1;
				}
				else
					largest = (largest > m * n) ? largest : m * n;
			}
		}
	}
	
	if(flag)
		printf("\nLargest Palindrome is %u", largest);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n%G",time_spent);
	
	return 0;
}	

int check_palindrome(unsigned long int n)
{
	unsigned long int t1, t2, r;
	t1 = n;
	while(t1)
	{
		r = t1 % 10;
		t1 = t1 / 10;
		t2 = t2 * 10 + r;
	}
	
	if(t2 == n)
		return 1;
	else
		return 0;
}
