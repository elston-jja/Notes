#include <stdio.h>


int max_of_3(int, int, int);
int min_of_3(int, int, int);
int mid_of_3(int, int, int);


int main()
{

    int a,b,c;

    int max, min, mid;

    printf("Please enter a value for a,b,c: ");
    scanf("%d %d %d",&a,&b,&c);

    max = max_of_3(a,b,c);
    min = min_of_3(a,b,c);
    mid = mid_of_3(a,b,c);

    printf("The value from least to greatest are: %d %d %d", min,mid,max);
    
    return 0;
}


int max_of_3(int a, int b, int c)
{
    if (a > b && a > c)
	return a;
    else if (b > a && b > c)
	return b;
    else
	return c;
}

int min_of_3(int a, int b, int c)
{
    if (a < b && a < c)
	return a;
    else if (b < a && b < c)
	return b;
    else
	return c;
}


int mid_of_3(int a, int b, int c)
{
    int max, min;
    max = max_of_3(a,b,c);
    min = min_of_3(a,b,c);

    if ( a != max && a != min)
	return a;
    else if (b != max && b != min)
	return b;
    else
	return c;
}
