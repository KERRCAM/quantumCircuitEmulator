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

    return 0;

}

/*--------------------------------------------------------------------------------------------------------------------*/






