#include <stdio.h>

#define LIMIT 1000

int main()
{
  int i, sum = 0;
	
	for(i = 1; i < LIMIT; i++)
		if(!(i % 3) || !(i % 5))
			sum += i;
	
	printf("\nSum is %d", sum);
	return 0;
}
