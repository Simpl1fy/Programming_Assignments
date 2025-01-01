#include<stdio.h>
#include<math.h>

void calculate_decimal_to_binary(int decimal_number) {
    int binary_number_array[32];

    int i=0;
    while(decimal_number > 0) {
        binary_number_array[i] = decimal_number % 2;
        decimal_number = decimal_number / 2;
        i++;
    }

    printf("Binary Number: ");
    for(int j=i-1; j>=0; j--) {
        printf("%d", binary_number_array[j]);
    }
    printf("\n");
}

void calculate_binary_to_decimal(int binary_number) {
    int decimal_number = 0;
    int i = 0;
    int remainder;

    while(binary_number != 0) {
        remainder = binary_number % 10;
        binary_number = binary_number / 10;
        decimal_number = decimal_number + remainder * pow(2, i);
        i++;
    }

    printf("Decimal Number: %d\n", decimal_number);
}


void calculate_decimal_to_octal(int decimal_number) {
    int octal_number_array[32];

    int i=0;
    while(decimal_number != 0) {
        octal_number_array[i] = decimal_number % 8;
        decimal_number = decimal_number / 8;
        i++;
    }

    printf("Octal Number: ");
    for(int j=i-1; j>=0; j--) {
        printf("%d", octal_number_array[j]);
    }
    printf("\n");
}

void calculate_octal_to_decimal(int octal_number) {
    int decimal_number = 0;
    int i=0;
    int remainder;

    while(octal_number != 0) {
        remainder = octal_number % 10;
        octal_number = octal_number / 10;
        decimal_number = decimal_number + remainder * pow(8, i);
        i++;
    }
    printf("Decimal Number: %d\n", decimal_number);
}

void calculate_hexadecimal_to_binary(char hexadecimal_number[]) {
    int i=0;

    printf("Binary Number: ");
    while(hexadecimal_number[i]) {
        switch(hexadecimal_number[i]) {
            case '0':
                printf("0000"); break;
            case '1':
                printf("0001"); break;
            case '2':
                printf("0010"); break;
            case '3':
                printf("0011"); break;
            case '4':
                printf("0100"); break;
            case '5':
                printf("0101"); break;
            case '6':
                printf("0110"); break;
            case '7':
                printf("0111"); break;
            case '8':
                printf("1000"); break;
            case '9':
                printf("1001"); break;
            case 'A':
            case 'a':
                printf("1010"); break;
            case 'B':
            case 'b':
                printf("1011"); break;
            case 'C':
            case 'c':
                printf("1100"); break;
            case 'D':
            case 'd':
                printf("1101"); break;
            case 'E':
            case 'e':
                printf("1110"); break;
            case 'F':
            case 'f':
                printf("1111"); break;
            case '.':
                printf("."); break;
            default:
                printf("Invalid Hexadecimal Number %c\n", hexadecimal_number[i]);
        }
        i++;
    }
    printf("\n");
}

void calculate_binary_to_hexadecimal(int binary_number) {
    int hexadecimal_number = 0;
    int i = 1;
    int remainder;

    while(binary_number != 0) {
        remainder = binary_number % 10;
        binary_number = binary_number / 10;
        hexadecimal_number = hexadecimal_number + remainder * i;
        i *= 2;
    }

    printf("Decimal Number: %X\n", hexadecimal_number);
}


int main() {
    int decimal_number;
    int binary_number;
    int octal_number;
    char hexadecimal_number[100];

    int loop = 1;
    int choice;


    while(loop) {

        printf("\n*****Number System Conversion*****\n");
        printf("1. Decimal to Binary\n2. Binary to Decimal\n3. Decimal to Octal\n4. Octal to Decimal\n5. Hexadecimal to Binary\n6. Binary to Hexadecimal\n7. Exit\n");
        printf("**********************************\n");


        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter decimal number: ");
                scanf("%d", &decimal_number);
                calculate_decimal_to_binary(decimal_number);
                break;
            case 2:
                printf("Enter binary number: ");
                scanf("%d", &binary_number);
                calculate_binary_to_decimal(binary_number);
                break;
            case 3:
                printf("Enter decimal number: ");
                scanf("%d", &decimal_number);
                calculate_decimal_to_octal(decimal_number);
                break;
            case 4:
                printf("Enter octal number: ");
                scanf("%d", &octal_number);
                calculate_octal_to_decimal(octal_number);
                break;
            case 5:
                printf("Enter hexadecimal number: ");
                scanf("%s", hexadecimal_number);
                calculate_hexadecimal_to_binary(hexadecimal_number);
                break;
            case 6:
                printf("Enter binary number: ");
                scanf("%d", &binary_number);
                calculate_binary_to_hexadecimal(binary_number);
                break;
            case 7:
                loop = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}