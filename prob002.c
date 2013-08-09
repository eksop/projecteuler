#include <stdio.h>

#define LIMIT 1000

int main()
{
  long int n, p1, p2, sum = 0;
	
	p1 = 1;
	p2 = 2;
	sum += p2;
	while((n = p1 + p2) < 4000000L)
	{
		if(!(n % 2))
			sum += n;
		p1 = p2;
		p2 = n;
	}
	
	printf("\nSum is %d", sum);
	return 0;
}
