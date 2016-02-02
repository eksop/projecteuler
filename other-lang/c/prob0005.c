#include <stdio.h>
#include <math.h>

#define RANGE 20

unsigned long int divisibility ( unsigned long int, unsigned long int );

int main()
{
	unsigned long int i, j, flag = 0;
	
	for(i = 1; !flag; i++)
	{
		for(j = 1; j <= RANGE; j++)
			flag += divisibility(i, j);
		
		if(flag == RANGE)
			flag = 1;
		else
			flag = 0;
	}
	
	printf("\nResult is %u", i - 1);

	return 0;
}	

unsigned long int divisibility (unsigned long int a, unsigned long int b)
{
	if( !(a % b) )
		return 1;
	else
		return 0;
}