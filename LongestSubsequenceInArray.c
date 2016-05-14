#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestSeq(int input1[],int size)
{
	int i = 0 ,j = 0,k = 0;
	int rslt = 1;
	int count = 0;
	int num = 0;
	int *lic = (int *)malloc(sizeof(int) * size);
	memset(lic,-1,size);
	for(i=0;i<size;i++)
	{
		int count = 0;
		for(j=0;j<rslt;j++)
		{
			if(lic[j] >= input1[i] && count == 0)
			{
				lic[j] = input1[i];
				count++;
			}
		}
		if(count == 0)
		{
			lic[rslt] = input1[i];
			rslt++;
		}
	}
	free(lic);
	return rslt - 1;
}

int main()
{
	int array[]={0,3,4,12,2,10,17,14,1,9,5,13,8,11,7,15};
	int result = 0;
	int i =0;
	result = longestSeq(array,sizeof(array)/sizeof(int));
	printf("\n[");
	for(i=0;i < sizeof(array)/sizeof(int) - 1;i++)
		printf("%d ,",array[i]);
	printf("%d]\nResult = %d\n",array[i],result);
	return 0;
}
