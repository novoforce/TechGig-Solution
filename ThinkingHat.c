#include<stdio.h>
#include<string.h>
#include<malloc.h>

void swap (int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


int permute(int a[], int i, int n)
{
	int j = 0,k = 0;
	int sum = 0;
	int inv = 0;
	int sort[30] = {0};
	static int out = 0;
	if (i == n)
	{
		sum = 0;
		inv = 0;
		for(j=0;j<n;j++)
			sort[j] = a[j];

		for(j = 0;j < n;j++)
		{
			for(k = j + 1;k < n;k++)
			{
				if(sort[j] > sort[k])
					swap((sort+j),(sort+k));
			}
		}

		for(j = n-1 ; j >=0 ;j--)
		{
			if(a[j] != sort[j])
			{
				for(k = 0;k < n;k++)
				{   
					if( a[j] == sort[k])
					{
						if(k < j)
							sum = sum + j - k;
					}
				}
			}
		}

		for(j = 0;j < n;j++)
		{
			for(k = j+1;k < n;k++)
			{
				if(a[j] > a[k])
					inv++;
			}
		}

		if(sum == inv)
			out++;
	}
	else
	{
		for (j = i; j < n; j++)
		{
			swap((a+i), (a+j));
			permute(a, i+1, n);
			swap((a+i), (a+j));
		}
	}
	if(out > 0)
		return out;
	else
		return -1;
}

int correctResult(int input1,int input2[],int len)
{
	int i = 0,j=0;
	int count = 1;
	int out = 0;
	int *input3 = (int *)malloc(input1 * sizeof(int));
	memset(input3,0,input1);
	for(i=0;i<len;i++)
		input3[i] = input2[i];
	for(i=len;i<input1;i++)
	{
		for(j=0;j<len;j++)
		{
			if(input2[j] == count)
			{
				count++;
				i--;
				break;
			}
		}
		if(j == len)
		{
			input3[i] = count;
			count++;
		}
	}
	out = permute(input3,len,input1);
	free(input3);
	return out;
}

int main()
{
	int str[] = {1,4};
	int len=0,i;
	int out = 0;
	len = sizeof(str)/sizeof(int);
	out = correctResult(5,str,len);
	printf("Result = %d\n",out);
	return 0;
}
