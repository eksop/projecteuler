#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define N 3
#define SIZE 5

int num[N][N];

unsigned long long int solve(int, int);

int main()
{
	int i, j, k, ch;
	unsigned long long int sum, temp;
	
	FILE *fp;
	fp = fopen("prob0018.txt","r");
	
	for(i = 0; i < N && !feof(fp); i++)
	{
		for(j = 0; j <= i && !feof(fp);)
		{
			fscanf(fp,"%d",&ch);
			num[i][j++] = ch;
			//printf("%3d",ch);
		}
		//printf("\n");
	}
	fclose(fp);
		
	sum = solve(0, 0);
	
	printf("\nSum is : %d", sum);
	return 0;
}

unsigned long long int solve(int i, int j) 
{
	unsigned long long int sol = 0, a, b, c;

 			if(i + 1 < N)
			{
				if((j + 1 <= i + 1) && (j + 1 < N))
				{
					if((j - 1 <= i + 1) && (j - 1 >= 0))
					{
						a = num[i][j];
						a += solve(i + 1, j);
						
						b = num[i][j];
						b += solve(i + 1, j + 1);
						
						c = num[i][j];
						c += solve(i + 1, j - 1);
						
						sol = a > b ? (a > c ? a : c) : (b > c ? b : c) ;
					
						return sol;
					}
					else
					{
					
						a = num[i][j];
						a += solve(i + 1, j);
						
						b = num[i][j];
						b += solve(i + 1, j + 1);
						
						sol = a > b ? a : b;
			
						return sol;
					}
				}
				else
				{
					if((j - 1 <= i + 1) && (j - 1 >= 0))
					{
					
						a = num[i][j];
						a += solve(i + 1, j);
						
						b = num[i][j];
						b += solve(i + 1, j - 1);
						
						sol = a > b ? a : b;
					
						return sol;
					}
					else
					{
						
						sol = num[i][j];
						sol += solve(i + 1, j);
						
						return sol;
					}
				}
			}
			else
			{
			
				sol = num[i][j];
				
				return sol;
			}
}