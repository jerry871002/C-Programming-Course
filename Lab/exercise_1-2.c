#include <stdlib.h>
#include <stdio.h>

int main()
{
    //* Exercise 1-2: Four basic arithemetic operations */
	
    int num1;
    int num2;
    int sum, difference, product, quotient;
    int times;
    
    printf("How many times do you want to calculate?");
    scanf("%d", &times);
    
    // Write Your Code Here
    for(int i = 1; i <= times; i++)
    {
        //input
        printf("Please enter two numbers:");
        scanf("%d %d", &num1, &num2);
        //calculate
        sum = num1 + num2;
        difference = num1 - num2;
        product = num1 * num2;
        quotient = num1 / num2;
        //output
    	printf("The sum of %d and %d is %d.\n", num1, num2, sum);
        printf("The difference between %d and %d is %d.\n", num1, num2, difference);
        printf("The product of %d and %d is %d.\n", num1, num2, product);
        printf("When %d is divided by %d, the quotient is %d.\n\n", num1, num2, quotient);
    }
    return 0;
}