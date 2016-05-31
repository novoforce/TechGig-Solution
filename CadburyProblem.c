#include<stdio.h>
#include<string.h>

int NoOfStudent(int min,int max)
{
	int out = 0;
	int temp = 0;
	while(min < max)
	{
		max = max - min;
		if(max < min)
		{
			temp = min;
			min = max;
			max =  temp;
		}
		out++;
	}
	return out + 1;
}

int cadbury(int input1,int input2,int input3,int input4)
{
	int i = input3;
	int res = 0;
	while(input1 <= input2)
	{
		i = input3;
		while(i <= input4)
		{
			if(input1 < i)
				res += NoOfStudent(input1,i);
			else
				res += NoOfStudent(i,input1);
			i++;
		}
		input1++;
	}
	return res;
}

int main()
{
	printf("Result : %d\n",cadbury(5,6,3,4));
	return 0;
}
