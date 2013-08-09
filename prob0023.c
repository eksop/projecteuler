#include <stdio.h>

#define N 10000

int main()
{
	int i, j, sum[N], s;
	
	for(i = 1; i < N; i++)
	{
		sum[i] = 0;
		for(j = 1; j < i; j++)
		{
			if(!(i % j))
			sum[i] += j;
		}
	}
	
	s = 0;
	for(i = 1; i < N; i++)
	{
		for(j = i + 1; j < N; j++)
		{
			if(sum[i] > i && sum[j] > i)
			{
				if(sum[j])
				sum -= -1;
		}
	}
	
	printf("\nSum is %d",s);
	return 0;
}



#include <stdio.h>

#define N 28123

void sum(int *, int *, int *);

int main()
{
	int i, p1[N], p2[N], n[N], flag = 0, term, c = 0, *ptr, *pt1, *pt2, *tmp;
	
	term = 2;
	s = 0;
	for(i = 1; i <= N; i++)
	{
	
	
	pt2[N - 1] = pt1[N - 1] = 1;
	
	while(!flag)
	{				
		term++;
		sum(ptr, pt1, pt2);
		
		for (c = 0; !ptr[c] ; c++);
		
		tmp = pt2;
		pt2 = pt1;
		pt1 = ptr;
		ptr = tmp;
	
		if( c == 0 )
		{
			flag = 1;
			ptr = pt1;
		}

	}
	
	printf("\nThe no is : ");
	
	for( i = 0; i < N; i++)
		printf("%d",ptr[i]);

	printf("\nThe term is : %d", term);
	
	return 0;
}

void sum(int *c, int *b, int *a)
{
	int i, j, temp, carry = 0;
	
	for(i = N - 1; i >= 0; i--)
	{
		c[i] = a[i] + b[i];
		c[i] += carry;
		temp = c[i];
		c[i] = temp % 10;
		carry = temp / 10;
	}
}

void copy(int *b, int*a)
{
	int i;
	
	for(i = 0; i < N; i++)
	{
		b[i] = a[i];
	}
}

int num_check(int n)
{
	int j, s = 0;
	
	for(j = 1; j <= n ; j++)
	{
		if(!(n % j))
			s += j;
	}
	if(s == n)
		return 0;
	else if(s < n)
		return -1;
	else
		return 1;
}