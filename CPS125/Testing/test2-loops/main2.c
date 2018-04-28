#include <stdio.h>

int main()
{
	int number, sum;
	sum = 0; number = 1;
	do 
	{
		sum = sum + number;
		++number;
	}while (sum <= 5); // see the ; here 
	printf ("The sum is %d.\n", sum);
	printf ("The number is %d.\n", number);
}
