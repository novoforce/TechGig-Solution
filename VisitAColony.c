#include<stdio.h>
#include<string.h>

int house_condition(int input1[],int input2)
{
	int i = 0,out = 0;
	int size = 0;
	while(input1[size] != -9999)
		size++;
	int *input3 = (int *)malloc(sizeof(int) * size);
	memset(input3,-1,size);
	for(i = 0 ;i < size;i++)
	{
		if(i == 0)
		{
			input3[0] = 1;
			if(i+1 < size)
			{
				input3[i+1] = input1[i] - input3[i];
			}
		}else{
			if(i+1 < size)
			{
				input3[i+1] = input1[i] - (input3[i-1] + input3[i]);
			}
		}
	}
	for(i = 0;i < size;i++)
	{
		if(input3[i] == -1)
		{
			free(input3);
			return -1;
		}

		out = input3[input2-1];
		free(input3);
		return out;
	}
}
