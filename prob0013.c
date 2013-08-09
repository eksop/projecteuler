#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define N 100
#define DIGITS 50

int main()
{
	int num[N][DIGITS], i, j, k, d;
	int carry, temp, sum[N];
	unsigned char ch;
	FILE *fp;
	fp = fopen("prob0013.txt","r");

		for(i = 0; i < 100 && !feof(fp); i++)
		{
			for(j = 0; j < 50 && !feof(fp);)
			{
				fscanf(fp,"%c",&ch);
				if(isdigit(ch))
					num[i][j++] = ch - '0';
			}
		}
		fclose(fp);

		for(k = 0; k < 100; k++)
			sum[k] = 0;
		
		carry = 0;
		
		for(j = 50 - 1, k = 100 - 1, d = 1; j >= 0; j--, k--, d++)
		{
			sum[k] += carry;
			for(i = 0; i < 100; i++)
			{
				sum[k] +=  num[i][j];
			}
			if(sum[k] > 9)
			{
				temp = sum[k];
				sum[k] = temp % 10;
				carry = temp / 10;
			}
		}
		
		for(;k >= 0 && carry;)
		{
				sum[k--] = carry % 10;
				carry = carry / 10;
		}
		
		printf("\nFirst 10 digits are : ");
		
		for(k = k + 1, i = 0; i < 10; i++)
		{
			printf("%d",sum[k++]);
		}
		
		return 0;
}
