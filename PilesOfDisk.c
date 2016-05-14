#include <stdio.h>
#include <string.h>

int get_order(int input1[],int count)
{
	int p = 0;
	int i =0,j=0,k=0,len = count;

	for(j=0;j<count;j++)
	{
		if(input1[j] == count)
			break;
	}

	for(i=j-1;i>=0;i--)
	{
		if(input1[i] == count - 1)
		{
			p = 0;
			for(k=i;k>=0;k--)
			{
				if(input1[k] == --len)
				{
					p++;
				}
			}
			break;
		}
	}
	return (count - 1 - p);
}

int main()
{
	int input1[] = {3,4,2,5,1};
	int min = get_order(input1,sizeof(input1)/sizeof(int));
	printf("MINIMUM = %d\n",min);
	return 0;
}
