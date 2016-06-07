#include<stdio.h>
#include<string.h>

int ThirstyCrowProblem(int input1[],int input2,int input3)
{
	int i = 0,j = 0;
	int out = 0;
	int temp;
	for(i = 0;i < input2 - 1;i++)
	{
		for(j = i + 1;j < input2;j++)
		{
			if(input1[i] > input1[j])
			{
				temp = input1[i];
				input1[i] = input1[j];
				input1[j] = temp;
			}
		}
	}
	for(i = 0;i < input2;i++)
	{
		if(i < input3)
		{
			out += input1[i];
			j = input1[i];
		}
		else if(j != input1[i])
			out += j;
	}
	return out;
}

int main()
{
	int input1[] = {5,58,10};
	int input2 = 3;
	int input3 = 1;
	printf("Output : %d\n",ThirstyCrowProblem(input1,input2,input3));
	return 0;
}
