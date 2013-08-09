#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define N 100

int main()
{
	unsigned long long int mat[N][N], i, j, n = 0, largest = 0, product, ri;
	
	FILE *fp;
	
	if ( ( fp = fopen("prob0011.txt", "r")) == NULL )
	{
		printf( "File could not be opened\n" );
	}
	else
	{
		for(n = 0; !feof(fp); n++)
		{
			fscanf(fp,"%d",&ri);
		}
		
		n = sqrt(n);
		//fclose(fp);
		//fp = fopen("prob0011.txt", "r");
		fseek(fp, 0, SEEK_SET);
		for(i = 0; i < n && !feof(fp); i++)
		{
			for(j = 0; j < n && !feof(fp); j++)
			{
				fscanf(fp,"%d",&ri);
				mat[i][j] = ri;
			}
		}
		
		fclose(fp);
		largest = mat[0][0] * mat[0][1] * mat[0][2] * mat[0][3];
		
		for(i = 0; i < n ; i++)
		{
			for(j = 0; j < n - 3; j++)
			{
				product = mat[i][j] * mat[i][j + 1] * mat[i][j + 2] * mat[i][j + 3];
				largest = largest > product ? largest : product;
			}
		}
		for(i = 0; i < n - 3 ; i++)
		{
			for(j = 0; j < n; j++)
			{
				product = mat[i][j] * mat[i + 1][j] * mat[i + 2][j] * mat[i + 3][j];
				largest = largest > product ? largest : product;
			}
		}
		for(i = 0; i < n - 3 ; i++)
		{
			for(j = n - 1; j > 3; j--)
			{
				product = mat[i][j] * mat[i + 1][j - 1] * mat[i + 2][j - 2] * mat[i + 3][j - 3];
				largest = largest > product ? largest : product;
			}
		}
		for(i = 0; i < n - 3 ; i++)
		{
			for(j = 0; j < n - 3; j++)
			{
				product = mat[i][j] * mat[i + 1][j + 1] * mat[i + 2][j + 2] * mat[i + 3][j + 3];
				largest = largest > product ? largest : product;
			}
		}
	}
	printf("\nLargest is %llu", largest);
	return 0;
}