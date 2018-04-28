#include <stdio.h>
#include <string.h>


typedef struct employee
{
    char name[20];
    int salary;
}emp;

int main()
{
    emp e1;

    printf("Please enter the name of the employee: ");
    scanf("%s", e1.name);
    
    printf("Please input the salary for elston: ");
    scanf("%d", &e1.salary);

    return 0;
}
