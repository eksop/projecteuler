#include <stdio.h>
#include <math.h>
#include <ctype.h>

int comp_date_le(int *, int*);
void inc_date(int *);

int st[4] = {1,1,1901,1}, en[4] = {31,12,2000,0};

int main()
{

	int a, sun = 0, *i = st, *j = en;
	
	for(; comp_date_le(i, j); inc_date(i))
	{
		if( (i[3] == 7) && (i[0] == 1) )
		{
			printf("\nTHE DATE IS %2d.%2d.%4d and day is %d",i[0],i[1],i[2],i[3]);
			sun++;
		}
	}
	
	printf("\nSundays are %d",sun);
}
	
	
	
int comp_date_le(int *a, int *b)
{
	if(a[2] < b[2])
	{
		return 1;
	}
	else
	{
		if(a[2] == b[2])
		{
			if(a[1] < b[1])
			{
				return 1;
			}
			else
			{
				if(a[1] == b[1])
				{
					if(a[0] <= b[0])
						return 1;
					else
						return 0;
				}
				else
					return 0;
			}
		}
		else
			return 0;
	}
}

void inc_date(int *a)
{
	if(a[0] < 28)
	{
		a[0] += 1;
		if(a[3] < 7)
			a[3] += 1;
		else
			a[3] = 1;
	}
	else 
	{
		if( a[0] == 28)
		{
			if( a[1] == 2 )
			{
				if( (!(a[2] % 400)) || ( (!(a[2] % 4)) && ((a[2] % 100)) ) ) 
				{
					a[0] += 1;
					if(a[3] < 7)
						a[3] += 1;
					else
						a[3] = 1;
				}
				else
				{
					a[0] = 1;
					if(a[3] < 7)
						a[3] += 1;
					else
						a[3] = 1;
					a[1] += 1;
				}
			}
			else
			{
				a[0] += 1;
				if(a[3] < 7)
					a[3] += 1;
				else
					a[3] = 1;
			}
		}
		else
		{
			if(a[0] == 29)
			{
				if(a[1] == 2)
				{
					a[0] = 1;
					if(a[3] < 7)
						a[3] += 1;
					else
						a[3] = 1;
					a[1] += 1;
				}
				else
				{
					a[0] += 1;
					if(a[3] < 7)
						a[3] += 1;
					else
						a[3] = 1;
				}
			}
			else
			{
				if(a[0] == 30)
				{
					if( (a[1] == 4) || (a[1] == 6) || (a[1] == 9) || (a[1] ==11) )
					{
						a[0] = 1;
						if(a[3] < 7)
							a[3] += 1;
						else
							a[3] = 1;
						a[1] += 1;
					}
					else
					{
						a[0] += 1;
						if(a[3] < 7)
							a[3] += 1;
						else
							a[3] = 1;
					}
				}
				else
				{
					a[0] = 1;
					if(a[3] < 7)
						a[3] += 1;
					else
						a[3] = 1;
					if(a[1] < 12)
						a[1] += 1;
					else
					{
						a[1] = 1;
						a[2] += 1;
					}
				}
			}
		}
	}
}