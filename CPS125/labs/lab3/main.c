#include <stdio.h>
#include <math.h>

int main(void)
{
    int num1,num2,num3,num4,sumTotal,sumDifference,sumSquares;
    double sumSqrt;

    printf("Please input values for num 1-4: \n");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    sumTotal = num1+num2+num3+num4;
    sumDifference = (num1+num2)-(num3+num4);

    sumSquares = num1*num1 + num2*num2 + num3*num3 + num4*num4;

    sumSqrt = sqrt(sumSquares)/(double)(sumTotal);

    printf("The sum total is: %d\n", sumTotal);
    printf("The difference between the first two and last two integers %d\n", sumDifference);
    printf("The sum of the squares is: %d\n", sumSquares);
    printf("The square root of the sum of squares divided by the sum totoal is: %.2lf\n", sumSqrt);

    return 0;
}
