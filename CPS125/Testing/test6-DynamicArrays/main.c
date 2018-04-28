#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int * array;
    size_t size;
    size_t used;
} Array;

void initArray(Array *a, size_t initialSize)
{
    a -> array = (int*)malloc(initialSize*sizeof(int));
    a -> used = 0;
    a -> size = initialSize;
}

void insertArray(Array *a, int element)
{
    // If reached a max amount of items
    if (a -> used == a -> size)
    {
	// double the initlal sizez
	a-> size *= 2;
	// allocate twice the amount of memory
	a -> array = (int *)realloc(a-> array, a-> size * sizeof(int));
    }

    // Add the elemnt to the array in the spot used
    a -> array[ a -> used++ ] = element;
}

void freeArray(Array * a)
{
    free(a->array);
    a-> array = NULL;
    a-> used = a -> size = 0;
}

void printArray(Array *a)
{
    for (int i = 0; i < a -> used; i++)
    {
	printf("%d\n", a->array[i]);
    }
}

int main(void)
{
    Array a;
    initArray(&a,5);

    for (int i = 0; i < 100; i++)
    {
	insertArray(&a, i);
    }
    printf("%d\n", a.array[9]);

    printf("%d\n", a.used);

    printf("The current elements in the array are: \n");

    printArray(&a);
    
    freeArray(&a);
    
    return 0;
}
