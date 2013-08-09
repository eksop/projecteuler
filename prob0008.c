#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define RANGE 10000

int main()
{
	unsigned long int i, c, largest, product, n[RANGE];
	unsigned char ch;
	
	FILE *fp;
	
	if ( ( fp = fopen("prob0008.txt", "r")) == NULL )
	{
		printf( "File could not be opened\n" );
	}
	else
	{
		for(c = 0; !feof(fp); )
		{
			fscanf(fp,"%c",&ch);
			if(isdigit(ch))
				n[c++] = ch - '0';
		}
		
		largest = n[0] * n[1] * n[2] * n[3] * n[4] ;
	
		for(i = 1; i < c - 4; i++)
		{
			product = n[i] * n[i + 1] * n[i + 2] * n[i + 3] * n[i + 4] ;
			largest = largest > product ? largest : product ;
		}
	}
	printf("\nLargest product of 5 consecutive digits is %u",largest);
	
	return 0;
}