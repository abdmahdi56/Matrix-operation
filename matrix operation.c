#include <stdio.h>

void add(int ra, int ca, int a[ra][ca], int b[ra][ca]);
void sub(int ra, int ca, int a[ra][ca], int b[ra][ca]);
void multi(int ra, int ca, int rb, int cb, int a[ra][ca], int b[rb][cb]);
void transpose(int r, int c, int matrix[r][c]);
void isSquareMatrix(int r, int c, char name);
int determinant(int n, int mat[n][n]);

int main()
{
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
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            printf("Enter [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the value of B matrix (%d*%d):\n", rb, cb);
    for (int i = 0; i < rb; i++)
    {
        for (int j = 0; j < cb; j++)
        {
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
    printf("6. Determinant of A\n");
    printf("7. Determinant of B\n");
    printf("8. Check if A is Identity matrix\n");
    printf("9. Check if B is Identity matrix\n");
    printf("10. Check if A is square\n");
    printf("11. Check if B is square\n");
    printf("12. Exit\n");


    while (1)
    {
        int n;
        printf("Choose operation: ");
        scanf("%d", &n);

        switch (n)
        {
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
            if (ra == ca)
                printf("\nDeterminant of A: %d\n", determinant(ra, a));
            else
                printf("\nDeterminant is only defined for square matrices.\n");
            break;
        case 7:
            if (rb == cb)
                printf("\nDeterminant of B: %d\n", determinant(rb, b));
            else
                printf("\nDeterminant is only defined for square matrices.\n");
            break;
        case 8:
            if (ra == ca)
            {
                isIdentityMatrix(ra, a);
            }
            else
            {
                printf("\nIdentity check is only valid for square matrices.\n");
            }
            break;
        case 9:
            if (rb == cb)
            {
                isIdentityMatrix(rb, b);
            }
            else
            {
                printf("\nIdentity check is only valid for square matrices.\n");
            }
            break;
        case 10:
            isSquareMatrix(ra, ca, 'A');
            break;

        case 11:
            isSquareMatrix(rb, cb, 'B');
            break;

        case 12:
            printf("\nThanks for using the program.\n");
            return 0;

        default:
            printf("\nInvalid choice, please try again.\n");
        }
    }
}

void add(int ra, int ca, int a[ra][ca], int b[ra][ca])
{
    printf("\nA + B:\n");
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
}

void sub(int ra, int ca, int a[ra][ca], int b[ra][ca])
{
    printf("\nA - B:\n");
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            printf("%d ", a[i][j] - b[i][j]);
        }
        printf("\n");
    }
}

void multi(int ra, int ca, int rb, int cb, int a[ra][ca], int b[rb][cb])
{
    printf("\nA * B:\n");
    int result[ra][cb];

    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < ca; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}



void transpose(int r, int c, int matrix[r][c])
{
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}

void isSquareMatrix(int r, int c, char name)
{
    if (r == c)
    {

        printf("\nMatrix %c is a square matrix.\n", name);
    }
    else
    {
        printf("\nMatrix %c is not a square matrix.\n", name);
    }
}
int determinant(int n, int mat[n][n])
{
    if (n == 1)
    {
        return mat[0][0];
    }
    if (n == 2)
    {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    if (n == 3)
    {
        return mat[0][0]*(mat[1][1]*mat[2][2] - mat[1][2]*mat[2][1]) -
               mat[0][1]*(mat[1][0]*mat[2][2] - mat[1][2]*mat[2][0]) +
               mat[0][2]*(mat[1][0]*mat[2][1] - mat[1][1]*mat[2][0]);
    }
    else
    {
        printf("Determinant calculation is only supported for 1x1, 2x2, and 3x3 matrices.\n");
    }
    return 0;
}
void isIdentityMatrix(int n, int mat[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == j && mat[i][j] != 1) || (i != j && mat[i][j] != 0))
            {
                printf("\nMatrix is NOT an identity matrix.\n");
                return;
            }
        }
    }
    printf("\nMatrix IS an identity matrix.\n");
}

