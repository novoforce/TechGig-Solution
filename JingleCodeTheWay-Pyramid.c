#include <stdio.h>
#include <string.h>

char *minimumCost(char *input1[],int input2)
{
	static char OutPut[256] = {0};
	char Path[256] = {0};
	int MinCostPath = atoi(input1[0]);
	int i = 0;
	int index = 0;
	int B = 0,D = 0,R = 0;
	for(i = 0;i < input2;i++)
	{
		B = atoi(input1[i + 1] + index);
		D = atoi(input1[i + 1] + index + 2);
		R = atoi(input1[i] + index + 2);

		if(B < D && B < R)
		{
			MinCostPath += B;
			Path[i] = 'B';
		}
		else if(D < B && D < R)
		{
			MinCostPath += D;
			index = index + 2;
			Path[i] = 'D';
		}
		else
		{ 
			MinCostPath += R;
			index = index + 2;
			Path[i] = 'R';
		}
	}
	sprintf(OutPut,"%d,%s",MinCostPath,Path);
	return OutPut;
}

int main()
{
	char *input1[] = {"5#7#2#4","1#8#1#3","6#2#9#5","1#6#2#8"};
	int input2 = 4;
	printf("Output = %s\n",minimumCost(input1,input2));
	return 0;
}
