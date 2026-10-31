/* LIBRARY IMPORTS */
#include <stdio.h>
#include <complex.h>

/* LOCAL IMPORTS */
#include <matrix.h>

/*--------------------------------------------------------------------------------------------------------------------*/

int main(){


    matrix* a = newMatrix(2, 3);
    matrix* b = newMatrix(3, 2);
    double complex o = 1.0;
    double complex n = 1.0;

    for (int i = 0; i < a->h; i++){
        for (int j = 0; j < a->w; j++){
            a->mat[i * a->w + j] = n;
            n += o;
        }
    }
    for (int i = 0; i < b->h; i++){
        for (int j = 0; j < b->w; j++){
            b->mat[i * b->w + j] = n;
            n += o;
        }
    }

    printMatrix(a);
    printf("\n");
    printMatrix(b);
    printf("\n");

    matrix* result = matrixMult(a, b);
    printMatrix(result);
    printf("\n");

    matrix* tr = matrixTranspose(result);
    printMatrix(tr);

    // double complex z1 = 1.0 + 3.0 * I;
    // double complex z2 = 1.0 - 4.0 * I;

    // printf("Working with complex numbers:\n\v");

    // printf("Starting values:\nZ1 = %.2f + %.2fi\nZ2 = %.2f %+.2fi\n\n", creal(z1), cimag(z1), creal(z2), cimag(z2));

    // double complex sum = z1 + z2;
    // printf("The sum: Z1 + Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));

    // double complex difference = z1 - z2;
    // printf("The difference: Z1 - Z2 = %.2f %+.2fi\n", creal(difference), cimag(difference));

    // double complex product = z1 * z2;
    // printf("The product: Z1 x Z2 = %.2f %+.2fi\n", creal(product), cimag(product));

    // double complex quotient = z1 / z2;
    // printf("The quotient: Z1 / Z2 = %.2f %+.2fi\n", creal(quotient), cimag(quotient));

    // double complex conjugate = conj(z1);
    // printf("The conjugate of Z1 = %.2f %+.2fi\n", creal(conjugate), cimag(conjugate));

    return 0;

}

/*--------------------------------------------------------------------------------------------------------------------*/






