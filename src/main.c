/* LIBRARY IMPORTS */
#include <stdio.h>
#include <math.h>

/* LOCAL IMPORTS */
#include <matrix.h>
#include <gate.h>

/*--------------------------------------------------------------------------------------------------------------------*/

int main(){

    // matrix* a = newMatrix(2, 3);
    // matrix* b = newMatrix(3, 2);
    // double complex o = 1.0;
    // double complex n = 1.0;

    // for (int i = 0; i < a->h; i++){
    //     for (int j = 0; j < a->w; j++){
    //         a->mat[i * a->w + j] = n;
    //         n += o;
    //     }
    // }
    // for (int i = 0; i < b->h; i++){
    //     for (int j = 0; j < b->w; j++){
    //         b->mat[i * b->w + j] = n;
    //         n += o;
    //     }
    // }

    // printMatrix(a);
    // printf("\n");
    // printMatrix(b);
    // printf("\n");

    // matrix* result = matrixMult(a, b);
    // printMatrix(result);
    // printf("\n");

    // matrix* tr = matrixTranspose(result);
    // printMatrix(tr);
    // printf("\n");





    initBaseGates();
    // matrix* q0 = newMatrix(2, 1);


    // matrix* H = newMatrix(2, 2);
    // H->mat[0] = 1.0 * sqrt(0.5);
    // H->mat[1] = 1.0 * sqrt(0.5);
    // H->mat[2] = 1.0 * sqrt(0.5);
    // H->mat[3] = -1.0 * sqrt(0.5);
    // // printMatrix(H);
    // // printf("\n");

    // matrix* q0 = newMatrix(2, 1);
    // q0->mat[0] = 1.0;
    // printMatrix(q0);
    // printf("\n");

    // matrix* q1 = newMatrix(2, 1);
    // q1->mat[0] = 1.0;
    // // q1 = matrixMult(H, q1);


    // q0 = matrixMult(H, q0);
    // printMatrix(q0);
    // printf("\n");

    // matrix* sv = tensorProduct(q1, q0);
    // printMatrix(sv);
    // printf("\n");


    // matrix* b0 = newMatrix(2, 1);
    // matrix* b1 = newMatrix(2, 1);

    // b0->mat[0] = 1.0;
    // b1->mat[1] = 1.0;
    // printMatrix(b0);
    // printf("\n");
    // printMatrix(b1);
    // printf("\n");

    // matrix* tp = tensorProduct(b0, b1);
    // printMatrix(tp);
    // printf("\n");

    return 0;

}

/*--------------------------------------------------------------------------------------------------------------------*/






