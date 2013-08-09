#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define N 15

long int max(long int a, int b, int c);

long int num[N][N], store[N][N];

int main()
{
	long int i, j, ch, a, b, c;
	
	FILE *fp;
	fp = fopen("prob0018.txt","r");
	
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			num[i][j] = 0;	
			
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			store[i][j] = 0;
			
	for(i = 0; i < N && !feof(fp); i++)
	{
		for(j = 0; j <= i && !feof(fp);)
		{
			fscanf(fp,"%d",&ch);
			num[i][j++] = ch;
		}
	}
	
	fclose(fp);
	
	for(i = N - 1; i >= 0; i--)
	{
		printf("\n");
		for(j = i; j >= 0 ; j--)
		{
			a = b = c = 0;
			if(i + 1 < N)
			{
				if((j + 1 <= i + 1) && (j + 1 < N))
				{	

					a = store[i + 1][j];
					b = store[i + 1][j + 1];
					a = a > b ? a : b;
					store[i][j] = num[i][j] + a;
					printf(" %4u", store[i][j]);	
				}
				else
				{
					a = store[i + 1][j];
					store[i][j] = num[i][j] + a;
					printf(" %4u", store[i][j]);
				}
			}
			else
			{
				store[i][j] = num[i][j];
				printf(" %4u", store[i][j]);
			}
		}
	}

	printf("\nSum is : %d", store[0][0]);
	return 0;
}
