#include <stdio.h>

int main()
{
    FILE *data = fopen("lists.txt", "r");

    int data_max = 10;
    int array1[10];
    int array2[10];

    for(int i = 0; i < data_max; i++)
    {
    	fscanf(data,"%2d %2d", &array1[i], &array2[i]);
    }

    printf("Scanned values\n");

    printf("Array1 | Array 2\n");
    for(int n = 0; n < data_max; n++)
    {
    	printf("%3d    |  %3d\n", array1[n], array2[n]);
    }

    fclose(data);
}
