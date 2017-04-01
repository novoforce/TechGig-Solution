#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int GetJumpCount(int input1,int input2,int input3_size, int* input3)
{
	int result = 0;
	int jump = 0;
	int i;
	for(i = 1;i <= input3_size;i++)
	{
		jump = 0;
		if(input1 >= input3[i - 1])
			result++;
		else
		{
			while(jump + input1 < input3[i - 1])
			{
				jump = jump + input1 - input2;
				result++;
			}
			if(jump + input1 >= input3[i - 1])
				result++;
		}
	}
	return result;
}

int main() {
	int output = 0;
	int ip1;
	scanf("%d", &ip1);
	int ip2;
	scanf("%d", &ip2);
	int ip3_size = 0;
	int ip3_i;
	scanf("%d\n", &ip3_size);
	int ip3[ip3_size];
	for(ip3_i = 0; ip3_i < ip3_size; ip3_i++) {
		int ip3_item;
		scanf("%d", &ip3_item);

		ip3[ip3_i] = ip3_item;
	}
	output = GetJumpCount(ip1,ip2,ip3_size,ip3);
	printf("%d\n", output);
	return 0;
}
