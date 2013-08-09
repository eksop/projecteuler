#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define N 1000
#define SIZE (N / 2)

int main()
{
	unsigned long long int carry, num[SIZE], sum, temp;
	long long int i, j, k;
		
	for(k = 0; k < SIZE; k++)
		num[k] = 0;
	
	num[SIZE - 1] = 1;
	sum = 0;
	carry = 0;

	for(i = 1; i <= N; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			num[j] *= 2;
		}
		carry = 0;
		for(k = SIZE - 1; k >= 0; k--)
		{
			num[k] += carry;
			temp = num[k];
			num[k] = temp % 10;
			carry = temp / 10;
		}
	
		for(;k >= 0 && carry;)
		{	
			num[k--] = carry % 10;
			carry = carry / 10;
		}
	}

	for(j = 0; j < SIZE ; j++)
		printf("%llu ",num[j]);
	
	for(k = k + 1; k < SIZE ; k++)
		sum += num[k];

	printf("\nSum is : %llu", sum);
	return 0;
}
