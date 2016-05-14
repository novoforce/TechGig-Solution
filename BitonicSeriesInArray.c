#include<stdio.h>
#include<stdlib.h>

int bitonic(int arr[], int n)
{
	int size=n;
	int *bc=(int *)malloc(size * sizeof(int));
	int i,j,max=1;
	bc[0]=1;
	for(i=1;i<size;i++)
	{
		bc[i]=1;
		for(j=i-1;j>=0;j--)
		{
			if((bc[i]<bc[j]+1) && arr[i]>arr[j])
			{
				bc[i]=bc[j]+1;
			}
		}

		if(bc[i]>max)
		{
			max=bc[i];

		}
	}
	bc[size-1]=1;
	for(i=size-2;i>=0;i--)
	{
		int prv=bc[i];
		bc[i]=1;
		for(j=i+1;j<size;j++)
		{
			if((bc[i]<bc[j]+1) && arr[i] > arr[j])
			{
				bc[i]=bc[j]+1;
			}
		}
		if(prv+bc[i]-1 > max)
		{
			max=prv+bc[i]-1;
		}
	}
	return max;

}

int main()
{
	int arr[] = {1,11,2,10,4,5,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Length of max length Bitnoic Subarray is %d\n", bitonic(arr, n));
	return 0;
}
