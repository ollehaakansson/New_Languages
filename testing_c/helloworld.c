#include <stdio.h>
int main() {
   
   double num1, num2, result;
   char operator;

   printf("Enter first number: ");
   fflush(stdout);
   scanf("%lf", &num1);

   printf("Enter operator (+, -, ^, /): ");
   fflush(stdout);
   scanf(" %c", &operator);


   printf("Enter second number: ");
   fflush(stdout);
   scanf("%lf", &num2);

    switch (operator) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
    if(num2 != 0.0) {
            result = num1 / num2;
        }else{
            printf("Error");
            return 1;
        }
        break;
    default:
        printf("Not valid operator");
        return 0;
    }

   printf("Result: %.2lf\n", result);
   return 0;
}