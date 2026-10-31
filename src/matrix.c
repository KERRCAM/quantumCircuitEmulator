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

matrix* matrixMult(matrix* a, matrix* b){

    if (a->w != b->h){
        printf("ERROR: matrices dimensions cannot be multiplied (a.w = %d, b.h = %d)\n", a->w, b->h);
        exit(1);
    }

    matrix* result = newMatrix(a->h, b->w);

    // TODO: make first or second loop parallel, third would be race condition
    for (int i = 0; i < a->h; i++){
        for (int j = 0; j < b->w; j++){
            for (int k = 0; k < a->w; k++){
                result->mat[i * result->w + j] += a->mat[i * a->w + k] * b->mat[k * b->w + j];
            }
        }
    }

    return result;

}

/*--------------------------------------------------------------------------------------------------------------------*/

matrix* matrixTensorProd(matrix* a, matrix* b){

    return a;

}

/*--------------------------------------------------------------------------------------------------------------------*/

matrix* matrixTranspose(matrix* a){

    matrix* result = newMatrix(a->w, a->h);

    for (int i = 0; i < a->h; i++){
        for (int j = 0; j < a->w; j++){
            result->mat[j * result->w + i] = a->mat[i * result->w + j];
        }
    }

    return result;

}

/*--------------------------------------------------------------------------------------------------------------------*/

matrix* matrixConjugate(matrix* a){

    return a;

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

void deleteMatrix(matrix* m){

    free(m->mat);
    free(m);

}

/*--------------------------------------------------------------------------------------------------------------------*/
