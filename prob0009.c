#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define N 1000

int main()
{
	unsigned long int a, b, c, flag = 0, x, y, z;

	for(a = 1; !flag && a <= N; a++)
	{
		for(b = 1; !flag && b <= N ; b++)
		{
			c = N - a - b;
			x = a;
			y = b;
			z = c;
			
			/*c = ((z > x) ? ((z > y) ? z : y) : ((z > y) ? x : ((x > y) ? x : y)));
			b = ((y > x) ? ((y > z) ? ((x > z) ? x : z) : y) : ((y > z) ? y : ((y > z) ? x : z)));
			a = ((x < y) ? ((x < z) ? x : z) : ((x < z) ? y : ((y < z) ? y : z)));
			*/
			if(c * c == a * a + b * b)
				flag = 1;
		}
	}

	printf("\nValue of a = %u, b = %u, c = %u, abc = %u",a - 1, b - 1, c, (a - 1) * (b - 1) * c);
	return 0;
}