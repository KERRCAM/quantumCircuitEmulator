/* LIBRARY IMPORTS */
#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

/* LOCAL IMPORTS */
#include <matrix.h>

/*--------------------------------------------------------------------------------------------------------------------*/

matrix* newMatrix(int h, int w){

    /* Memory allocation */
    matrix* m = calloc(1, sizeof(*m));

    /* Initialising attributes */
    m->h = h;
    m->w = w;
    m->mat = calloc(1, sizeof(double complex) * h * w);

    return m;

}

/*--------------------------------------------------------------------------------------------------------------------*/

matrix* loadMatrix(int h, int w, double complex* mat){

    /* Memory allocation */
    matrix* m = calloc(1, sizeof(*m));

    /* Initialising attributes */
    m->h = h;
    m->w = w;
    m->mat = mat;

    return m;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void printMatrix(matrix* m){

    for (int i = 0; i < m->h; i++){
        printf("[ ");
        for (int j = 0; j < m->w; j++){
            printf("%f %+fi", creal(m->mat[i * m->w + j]), cimag(m->mat[i * m->w + j]));
            if (j != m->w - 1){ printf(", ");}
        }
        printf(" ]\n");
    }

}

/*--------------------------------------------------------------------------------------------------------------------*/