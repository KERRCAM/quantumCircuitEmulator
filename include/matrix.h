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

void printMatrix(matrix* m);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif
