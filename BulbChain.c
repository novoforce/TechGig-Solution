#include "stdlib.h"
#include "string.h"
#include "stdio.h"

int colorSequences(char* input1,char* input2)
{
	int len1 = strlen(input1);
	int len2 = strlen(input2);

	int sublen = 0;
	int i,j,out = 0,count = 0,temp = 0;
	char *substring;
	if(len1 > len2)
	{
		substring = strstr(input1,input2);
	}else{
		substring = strstr(input2,input1);
	}
	if(substring)
	{
		sublen = strlen(substring);
		if(len1 > len2)
			out = len1 - len2;
		else
			out = len2 - len1;
	}else{
		if(len1 > len2){
			for(i = 0; i < len2 ; i++)
			{
				for(j=temp ; j < len1 ; j++)
				{
					if(input2[i] == input1[j])
					{
						count++;
						temp = j + 1;
						break;
					}
				}
			}
			out = len1 - count;
		}else{
			for(i = 0; i < len1; i++)
			{
				for(j=temp ; j < len2 ; j++)
				{
					if(input1[i] == input2[j])
					{
						count++;
						temp = j + 1;
						break;
					}
				}
			}
			out = len2 - count;
		}

	}
	return out;
}

int main()
{
	char input1[100]={0};
	char input2[100]={0};
	int min = 0;
	printf("Enter Input 1 : ");
	scanf("%s",input1);
	printf("\nEnter Input 2 : ");
	scanf("%s",input2);
	min = colorSequences(input1,input2);
	printf("\nMinimum Number Of Transform : %d\n",min);
	return 0;
}
