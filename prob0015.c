#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define N (20 + 1)

unsigned long long int store[N][N];

unsigned long long int routes(unsigned int , unsigned int);

int main()
{
	unsigned int i, j;

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			store[i][j] = -1;	
	store[0][0] = routes(0, 0);
	
	printf("\nNo of routes available are : %llu", store[0][0]);

	return 0;
}

unsigned long long int routes(unsigned int i, unsigned int j) 
{
	if(store[i][j] == -1)
	{
		if ((i == N - 1) && (j == N - 1))
			store[i][j] = 1;
		else
			if(i + 1 < N)
				if(j + 1 < N)
					store[i][j] = routes(i + 1, j) + routes(i, j + 1);
				else
					store[i][j] = routes(i + 1, j);
			else
				if(j + 1 < N)
					store[i][j] = routes(i, j + 1);
				else
					store[i][j] = 0;
	}
	return store[i][j];
}