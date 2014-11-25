#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define N 1000
#define SIZE 100

int word1_9[] = {3,3,5,4,4,3,5,5,4};
int word10_19[] = {3,6,6,8,8,7,7,9,8,8};
int word20_90[] = {6,6,5,5,5,7,6,6};
int wordht[] = {7,8};
int and = 3;

unsigned int wordlength(unsigned int);

int main()
{
	unsigned long int sum = 0;
	int i;
		
	for(i = 1; i <= N; i++)
		sum += wordlength(i);
	
	printf("\nSum is : %u", sum);
	return 0;
}
unsigned int wordlength(unsigned int n)
{
	int i, j, c = SIZE - 1;
	unsigned int num[SIZE], temp = n, len = 0;
	
	for(i = 0; i < SIZE ; i++)
	{
		num[i] = 0;
	}
	
	for(;temp > 0;)
	{
		num[c--] = temp % 10;
		temp = temp / 10;
	}
	
	if(c == SIZE - 2)
		len = word1_9[num[SIZE - 1] - 1];
	if(c == SIZE - 3)
		if( num[SIZE - 2] == 1)
			len = word10_19[num[SIZE - 1]];
		else
			if(num[SIZE - 1] == 0)
				len = word20_90[num[SIZE - 2] - 2];
			else
				len = word20_90[num[SIZE - 2] - 2] + word1_9[num[SIZE - 1] - 1] ;
	if(c == SIZE - 4)
		if( num[SIZE - 2] == 0)
			if( num[SIZE - 1] == 0)
				len = word1_9[num[SIZE - 3] - 1] + wordht[0];
			else
				len = word1_9[num[SIZE - 3] - 1] + wordht[0] + and + word1_9[num[SIZE - 1] - 1];
		else
			if(num[SIZE - 2] == 1)
				len = word1_9[num[SIZE - 3] - 1] + wordht[0] + and + word10_19[num[SIZE - 1]];
			else
				if(num[SIZE - 1] == 0)
					len = word1_9[num[SIZE - 3] - 1] + wordht[0] + and + word20_90[num[SIZE - 2] - 2] ;
				else
					len = word1_9[num[SIZE - 3] - 1] + wordht[0] + and + word20_90[num[SIZE - 2] - 2] + word1_9[num[SIZE - 1] - 1] ;
		if(c == SIZE - 5)
			len = word1_9[num[SIZE - 4] - 1] + wordht[1];

		return len;	
}