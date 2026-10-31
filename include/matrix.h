#ifndef TOKEN_H
#define TOKEN_H

/* LIBRARY IMPORTS */
#include <stdio.h>
#include <complex.h>

/* LOCAL IMPORTS */


/*--------------------------------------------------------------------------------------------------------------------*/
/* STRUCTS */

typedef struct MATRIX{

    int w;
    int h;
    double complex* mat;

} matrix;

/*--------------------------------------------------------------------------------------------------------------------*/

matrix* newMatrix(int h, int w);

matrix* loadMatrix(int h, int w, double complex* mat);

matrix* matrixMult(matrix* a, matrix* b);

matrix* tensorProduct(matrix* a, matrix* b);

matrix* matrixTranspose(matrix* a);

matrix* matrixCompConj(matrix* a);

matrix* matrixConjTrans(matrix* a);

void printMatrix(matrix* m);

void deleteMatrix(matrix* m);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif
