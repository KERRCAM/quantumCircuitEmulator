/* LIBRARY IMPORTS */
#include <stdio.h>
#include <complex.h>

/* LOCAL IMPORTS */
#include <matrix.h>

/*--------------------------------------------------------------------------------------------------------------------*/

matrix* newMatrix(int w, int h, double complex* mat){

    /* Memory allocation */
    matrix* m = calloc(1, sizeof(*m));

    /* Initialising attributes */
    m->w = w;
    m->h = h;
    m->mat = mat;

    return m;

}

/*--------------------------------------------------------------------------------------------------------------------*/
