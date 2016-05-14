#include<stdio.h>
#include<string.h>

int sum_of_digit(int num)
{
	int rem = 0, d1 = 0;
	do{
		rem = num % 10;
		d1+=rem;
		num = num / 10;
	}while(num != 0);
	return d1;
}

int mul_of_digit(int num)
{
	int rem = 0, d2 = 1;
	do{
		rem = num % 10;
		d2*=rem;
		num = num / 10;
	}while(num != 0);
	return d2;
}

int smallest_number(int input1)
{
	int out = 0;
	int d1 = -1, n1 = 0, temp1 = 0, out1 = 0;
	int d2 = -1, n2 = 0, temp2 = 0, out2 = 0;
	while(input1 < input1 + 1000000000)
	{
		out = input1;
		temp1 = 0;
		temp2 = 0;
		while((out / 10) != 0)
		{
			out = sum_of_digit(out);
			temp1++;
		}
		out1 = out;
		out = input1;
		while((out / 10) != 0)
		{
			out = mul_of_digit(out);
			temp2++;
		}
		out2 = out;
		if(n1 == 0 && n2 == 0)
		{
			n1 = temp1;
			n2 = temp2;
			d1 = out1;
			d2 = out2;
		}
		else if(n1 >= temp1 && n2 >= temp2 && d1 == out1 && d2 == out2)
			return input1;
		input1++;
	}
	return -1;
}
