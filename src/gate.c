/* LIBRARY IMPORTS */
#include <complex.h>
#include <math.h>

/* LOCAL IMPORTS */
#include <matrix.h>

/*--------------------------------------------------------------------------------------------------------------------*/
/* BASE GATES */

matrix* identity;
matrix* hadamard;
matrix* pauliX;
matrix* pauliY;
matrix* pauliZ;
matrix* sGate;
matrix* tGate;
matrix* swap;
matrix* controlledNot;

/*--------------------------------------------------------------------------------------------------------------------*/

void initBaseGates(void){

    identity = newMatrix(2, 2);
    identity->mat[0] = 1.0;
    identity->mat[3] = 1.0;

    hadamard = newMatrix(2, 2);
    hadamard->mat[0] = 1.0 * sqrt(0.5);
    hadamard->mat[1] = 1.0 * sqrt(0.5);
    hadamard->mat[2] = 1.0 * sqrt(0.5);
    hadamard->mat[3] = -1.0 * sqrt(0.5);

    pauliX = newMatrix(2, 2);
    pauliX->mat[1] = 1.0;
    pauliX->mat[2] = 1.0;

    pauliY = newMatrix(2, 2);
    pauliY->mat[1] = -1.0 * I;
    pauliY->mat[2] = 1.0 * I;

    pauliZ = newMatrix(2, 2);
    pauliZ->mat[0] = 1.0;
    pauliZ->mat[3] = -1.0;

    sGate = newMatrix(2, 2);
    sGate->mat[0] = 1.0;
    sGate->mat[3] = 1.0 * I;

    tGate = newMatrix(2, 2);
    tGate->mat[0] = 1.0;
    tGate->mat[3] = (1.0 + 1.0 * I) / sqrt(2);

    swap = newMatrix(4, 4);
    swap->mat[0] = 1.0;
    swap->mat[6] = 1.0;
    swap->mat[9] = 1.0;
    swap->mat[15] = 1.0;

    controlledNot = newMatrix(4, 4);
    controlledNot->mat[0] = 1.0;
    controlledNot->mat[5] = 1.0;
    controlledNot->mat[11] = 1.0;
    controlledNot->mat[14] = 1.0;

    // matrix* result;
    // matrix* q0 = newMatrix(2, 1);
    // q0->mat[0] = 1.0;
    // matrix* q1 = newMatrix(2, 1);
    // q1->mat[0] = 1.0;

    // matrix* sv = tensorProduct(q0, q1);
    // printMatrix(sv);
    // printf("\n");

    // matrix* hxi = tensorProduct(hadamard, identity);
    // printMatrix(hxi);
    // printf("\n");

    // result = matrixMult(controlledNot, hxi);
    // printMatrix(result);
    // printf("\n");

    // result = matrixMult(result, sv);
    // printMatrix(result);
    // printf("\n");


    // result = matrixMult(hxi, sv);
    // printMatrix(result);
    // printf("\n");

    // result = matrixMult(controlledNot, result);
    // printMatrix(result);
    // printf("\n");





    // matrix* a = newMatrix(1, 2);
    // matrix* b = newMatrix(2, 1);
    // a->mat[0] = 1.0;
    // a->mat[1] = 2.0;
    // b->mat[0] = 3.0;
    // b->mat[1] = 4.0;
    // matrix* r = tensorProduct(a, b);
    // printMatrix(r);

}

/*--------------------------------------------------------------------------------------------------------------------*/

