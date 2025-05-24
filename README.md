# Matrix Operations in C

This is a console-based matrix calculator written in **C**, which allows users to perform various matrix operations including:

- Addition
- Subtraction
- Multiplication
- Transpose
- Determinant (up to 3x3)
- Identity matrix check
- Square matrix check

## 💡 Features

- Supports dynamic input for any matrix size
- Menu-driven user interface
- Handles basic errors and invalid operations
- Determinant logic included for 1x1, 2x2, and 3x3 matrices

## 🧮 Operations Menu

After entering matrix dimensions and values, choose from the following:

1. Addition (A + B)  
2. Subtraction (A - B)  
3. Multiplication (A * B)  
4. Transpose of Matrix A  
5. Transpose of Matrix B  
6. Determinant of Matrix A  
7. Determinant of Matrix B  
8. Check if Matrix A is Identity  
9. Check if Matrix B is Identity  
10. Check if Matrix A is Square  
11. Check if Matrix B is Square  
12. Exit the Program  

## 🔧 Compilation and Run

Make sure you're using a C99 (or later) compatible compiler (for Variable Length Arrays).

### On Linux/macOS:
```bash
gcc -o matrix_calculator matrix.c
./matrix_calculator
```

📌 Notes
.Matrix addition and subtraction are only valid when both matrices have the same dimensions.

.Multiplication is valid only if the number of columns in A equals the number of rows in B.

.Determinant is only computed for square matrices (1x1 to 3x3).

.Identity check is only applicable to square matrices.

🙋 Author
Abdullah Al Mahdi
BSc in Computer Science & Engineering
Leading University



