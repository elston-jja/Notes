#include <stdio.h>
#include <stdlib.h>

int main()
{
    float **a = (float**)malloc(3*sizeof(float*));
    for(int i = 0; i < 3; i++)
    {
	a[i] = (float*)malloc(3*sizeof(float));
    }
    
    for(int x = 0; x < 3; x++)
    {
	for(int y = 0; y < 3; y++)
	{
	    a[x][y] = 9;
	}
    }

    a[1][1] = 1;
    
    for(int x = 0; x < 3; x++)
    {
	for(int y  = 0; y < 3; y++)
	{
	    printf("%f\t", a[x][y]);
	}
	printf("\n");
    }

    
    printf("%f", a[1][1]);
    

    free(a);
    a = NULL;

    return 0;
}
