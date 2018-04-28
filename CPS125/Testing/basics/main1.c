#include <stdio.h>

int main(void)
{
    int a = 100;
    
    
    for (int i = 0; i+99 < a; i++)
    {
	printf("%d\n", i);
    }
    
    return 0;
}
