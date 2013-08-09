#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define N 100
#define S 1000
int main()
{
	unsigned long long int carry, num[S], sum, temp;
	long long int i, j;
		
	for(i = 0; i < S; i++)
		num[i] = 0;
	
	num[S - 1] = 1;
	
	sum = 0;
	carry = 0;

	for( j = N; j > 0; j--)
	{
		for(i = S - 1; i >= 0 ; i--)
		{	
			num[i] *= j;
			num[i] += carry;
			temp = num[i];
			num[i] = temp % 10;
			carry = temp / 10;
		}
	}
	
	printf("\nSum is : %llu", sum);
	return 0;
}
