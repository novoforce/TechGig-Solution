/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
int main(int argc, char *a[])
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i = 1;i <= n;i++)
	{
		for(j = i;j < n;j++)
			printf("  ");
		for(k = 1;k <= 2 * i - 1;k++)
		{
			printf("%d",abs((2 * i - 1)/2 - k + 1));
			if(k != 2 * i - 1)
				printf(" ");
		}
		printf("\n");
	}
}
