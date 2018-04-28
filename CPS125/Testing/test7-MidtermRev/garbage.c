#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t t;
    
    const char datFile[10] = "data.txt";
    FILE* data = fopen(datFile, "w+");
    int bound;

    do
    {
    printf("Please enter how many lines of grabage: ");
    scanf("%d", &bound);
    }
    while(bound < 0);

    srand((unsigned)time(&t));
    
    for(int i = 0; i < bound; i++)
    {
	fprintf(data, "%d \n", (int)rand());
    }
    printf("Successfully wrote %d lines of grabage to %s", bound, datFile);

    return 0;
    
	
}
