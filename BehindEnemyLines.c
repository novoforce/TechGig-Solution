#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int appearanceCount(int input1,int input2,char* input3,char* input4)
{
	int out = 0,i,j;
	int len1 = 0,len2 = 0;
	if(input2 < input1)
		return 0;
	for(i = 0;i < input1;i++)
	{
		len1 += input3[i];
	}

	for(i = 0;i <= input2 - input1;i++)
	{
		len2 = 0;
		for(j = i;j < i + input1;j++)
		{
			len2 += input4[j];	
		}
		if(len1 == len2)
			out++;
	}
	return out;
}


int main() {
	int output = 0;
	int ip1;
	scanf("%d", &ip1);
	int ip2;
	scanf("%d", &ip2);
	char* ip3;
	ip3 = (char *)malloc(512000 * sizeof(char));
	scanf("\n%[^\n]",ip3);
	char* ip4;
	ip4 = (char *)malloc(512000 * sizeof(char));
	scanf("\n%[^\n]",ip4);
	output = appearanceCount(ip1,ip2,ip3,ip4);
	printf("%d\n", output);
	return 0;
}
