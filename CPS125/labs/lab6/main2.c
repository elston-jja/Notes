#include <stdio.h>

int main (void)
{

    int a;

    do
    {
	printf("Please enter a value for a: ");
	scanf("%d", &a);
	
    } while(10 < a && a > 99);
    
    return 0;
}
