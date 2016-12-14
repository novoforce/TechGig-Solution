#include<stdio.h>
#include<string.h>

int nochange_bits(char* input1,int input2,int input3)
{
	int len = strlen(input1);
	char Buff[len];
	int output = 0;
	int i = 0;

	if(input2 <= 0 || input3 <= 0)
		return -1;

	strcpy(Buff,input1);
	for(i = 0;i < len;i++)
	{
		if((i+1)%input2 == 0)
		{
			if(input1[i] == 49)
				input1[i] = 48;
			else
				input1[i] = 49;
		}
		if((i+1)%input3 == 0)
		{
			if(input1[i] == 49)
				input1[i] = 48;
			else
				input1[i] = 49;
		}
	}
	for(i = 0;i < len;i++)
	{
		if(Buff[i] == input1[i])
			output++;
	}
	return output;
}

int main()
{
	char input1[] = "10110101101";
	int input2 = 3;
	int input3 = 4;
	printf("%d\n",nochange_bits(input1,input2,input3));
	return 0;
}
