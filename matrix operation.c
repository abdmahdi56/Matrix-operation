#include <stdio.h>

void add(int ra, int ca, int a[ra][ca], int b[ra][ca]);
void sub(int ra, int ca, int a[ra][ca], int b[ra][ca]);
void multi(int ra, int ca, int rb, int cb, int a[ra][ca], int b[rb][cb]);

void transpose(int r, int c, int matrix[r][c]);
void isSquareMatrix(int r, int c, char name);

int main() {
    int ra, ca, rb, cb;

    printf("Enter row of A matrix: ");
    scanf("%d", &ra);
    printf("Enter column of A matrix: ");
    scanf("%d", &ca);
    printf("Enter row of B matrix: ");
    scanf("%d", &rb);
    printf("Enter column of B matrix: ");
    scanf("%d", &cb);

    int a[ra][ca], b[rb][cb];

    printf("Enter the value of A matrix (%d*%d):\n", ra, ca);
    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < ca; j++) {
            printf("Enter [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the value of B matrix (%d*%d):\n", rb, cb);
    for (int i = 0; i < rb; i++) {
        for (int j = 0; j < cb; j++) {
            printf("Enter [%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nMENU:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");

    printf("4. Transpose of A\n");
    printf("5. Transpose of B\n");
    printf("6. Check if A is square\n");
    printf("7. Check if B is square\n");
    printf("8. Exit\n");


    while (1) {
        int n;
        printf("Choose operation: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if (ra == rb && ca == cb)
                    add(ra, ca, a, b);
                else
                    printf("\nAddition is not possible. Please try again.\n");
                break;

            case 2:
                if (ra == rb && ca == cb)
                    sub(ra, ca, a, b);
                else
                    printf("\nSubtraction is not possible. Please try again.\n");
                break;

            case 3:
                if (ca == rb)
                    multi(ra, ca, rb, cb, a, b);
                else
                    printf("\nMultiplication is not possible. Please try again.\n");
                break;



            case 4:
                printf("\nTranspose of Matrix A:\n");
                transpose(ra, ca, a);
                break;

            case 5:
                printf("\nTranspose of Matrix B:\n");
                transpose(rb, cb, b);
                break;

            case 6:
                isSquareMatrix(ra, ca, 'A');
                break;

            case 7:
                isSquareMatrix(rb, cb, 'B');
                break;

            case 8:
                printf("\nThanks for using the program.\n");
                return 0;

            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
}

void add(int ra, int ca, int a[ra][ca], int b[ra][ca]) {
    printf("\nA + B:\n");
    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < ca; j++) {
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
}

void sub(int ra, int ca, int a[ra][ca], int b[ra][ca]) {
    printf("\nA - B:\n");
    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < ca; j++) {
            printf("%d ", a[i][j] - b[i][j]);
        }
        printf("\n");
    }
}

void multi(int ra, int ca, int rb, int cb, int a[ra][ca], int b[rb][cb]) {
    printf("\nA * B:\n");
    int result[ra][cb];

    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < cb; j++) {
            result[i][j] = 0;
            for (int k = 0; k < ca; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < cb; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}



void transpose(int r, int c, int matrix[r][c]) {
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}

void isSquareMatrix(int r, int c, char name) {
    if (r == c)
    {

        printf("\nMatrix %c is a square matrix.\n", name);
    }
    else
    {
        printf("\nMatrix %c is not a square matrix.\n", name);
    }
}
