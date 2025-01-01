#include<stdio.h>
#include<math.h>

int main() {

    int choice;
    int loop = 1;

    int a, b;

    while(loop) {
        printf("\n***** Calculator *****\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Log\n6. Square Root\n7. Exit\n");
        printf("**********************\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                printf("Sum: %d\n", a+b);
                break;
            case 2:
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                printf("Difference: %d\n", a-b);
                break;
            case 3:
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                printf("Multiplication: %d\n", a*b);
                break;
            case 4:
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                printf("Division: %d\n", a/b);
                break;
            case 5:
                printf("Enter number: ");
                scanf("%d", &a);
                printf("Log: %f\n", log(a));
                break;
            case 6:
                printf("Enter number: ");
                scanf("%d", &a);
                printf("Square Root: %f\n", sqrt(a));
                break;
            case 7:
                loop = 0;
                break;
            default:
                printf("Invalid choice\n\n");
        }
    }

    return 0;
}