#include <stdio.h>
#include <stdlib.h>

// There exists a bug, if the data has 20 lines, we dont get an error, but if it contains 15 lines, we get an error
// Can only work for 1-5 9 10 19 20 39 40

// FIXED

typedef struct array
{
    int * array;
    size_t size;
    size_t used;
} Array;

void printArray(Array*a)
{
//    printf("%d", a-> used);
    for (int i = 0; i < a -> used; i++)
    {
	printf("%d\n", (a->array)[i]);
    }
}

int sort(Array* a, size_t n)
{
    int temp;
    
    if (n+1 < (a -> used))
    {
	if ((a -> array)[n] > (a -> array)[n+1])
	{
	    temp = (a -> array)[n];
	    (a -> array)[n] =  (a -> array)[n+1];
	    (a -> array)[n+1] = temp;
	}
	//printf("Printing Array\n\n");
	//printArray(a);
	sort(a, n+1);
    } 
}

int check(Array* a)
{
    for (int i = 0; i+1 < (a -> used); i++)
    {
	if((a -> array)[i] > (a -> array)[i+1])
	{
	    //printf("VALUES CAUSING CONFLICT: %4d %4d at %d\n", (a-> array)[i], (a-> array)[i+1], i+1);
	    return 0;
	}
    }
    return 1;
}

void initArray(Array* a, size_t initial)
{
    a -> array = (int*) malloc (initial*sizeof(int));
    a -> used = 0;
    a -> size = initial;
}

void insertArray(Array* a, int val)
{
    if (a -> used == a -> size)
    {
	a -> size = 2*(a -> size);
	a -> array = (int*)realloc( a-> array , (a ->size)*sizeof(int));
    }
    a -> array[ a -> used ++] = val;
}

void freeArray(Array *a)
{
    free(a-> array);
    a -> array = NULL;
    a -> used = a -> size = 0;
}

int main(void)
{
    int complete = 0;

    // Pointer for efficient sorting calls
    const char datFile[10] = "data.txt";
    const char savFile[11] = "stored.txt";
    
    Array a;

    initArray(&a,5);
    int temp;
    
    FILE * data = fopen("data.txt", "r");
    FILE * sorted = fopen("sorted.txt", "w+");

    printf("\nReading file \"%s\" for data\n", datFile);
    
    while(!feof(data))
    {
    	fscanf(data, "%d", &temp);
    	insertArray(&a, temp);
    }
    a.used --;

    if( a.used <= 0 || a.used > 32000)
    {
	printf("File too big or no numbers to sort");
	fclose(data);
	fclose(sorted);
	freeArray(&a);
	return 0;
    }
    
    printArray(&a);

    printf("\n---SORTING---\n");

    while (complete != 1)
    {
    	sort(&a, 0);

    	// Implement method to check if all elements are in order
    	complete = check(&a);
	//printf("\n\n%d\n\n", complete);
    }

    printf("\nCOMPLETE: \n");
    printArray(&a);    

    for (int i = 0; i < a.used - 1; i++)
    {
	fprintf(sorted, "%d \n", a.array[i]);
    }

    printf("Saved sorted output in file, \"%s\" " ,savFile);
    
    freeArray(&a);
    fclose(data);
    fclose(sorted);
    
    return 0;
}
