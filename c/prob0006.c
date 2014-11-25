#include <stdio.h>
#include <math.h>

#define RANGE 100

unsigned long int sum1N ( unsigned long int);
unsigned long int sumsq1N ( unsigned long int);

int main()
{
	unsigned long int s1N, sq1N, t, diff;
	
	s1N = sum1N(RANGE);
	sq1N = sumsq1N(RANGE);
	
	diff = s1N * s1N - sq1N;
	
	printf("\nResult is %u", diff);
	return 0;
}	


unsigned long int sum1N ( unsigned long int n)
{
	return (( n * (n + 1)) / 2); 
	
}
unsigned long int sumsq1N ( unsigned long int n)
{
	return (( n * (n + 1) * (2 * n + 1)) / 6); 
}
unsigned long int divisibility (unsigned long int a, unsigned long int b)
{
	if( !(a % b) )
		return 1;
	else
		return 0;
}