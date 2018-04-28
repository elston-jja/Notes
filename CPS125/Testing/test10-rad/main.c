#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int * local;
    int value;
} node;

int main()
{

    int ** a = malloc(4*sizeof(int));
    for(int i = 0; i < 4; i++)
    {
	a[i] = malloc(4*sizeof(int));
    }


    for (int z = 0; z < 4; z++)
    {
	for(int r = 0; r < 4; r++)
	{
	    printf("%d\t", a[z][r]);
	}
	printf("\n");
    }
    
    
    return 0;
}
