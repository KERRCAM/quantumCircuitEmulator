/* LIBRARY IMPORTS */
#include <complex.h>
#include <math.h>

/* LOCAL IMPORTS */
#include <matrix.h>
#include <gate.h>

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

gate newGate(int tag, int q0, int q1){

    gate g;

    /* Initialising attributes */
    g.tag = tag;
    g.q0 = q0;
    g.q1 = q1;

    return g;

}

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

}

/*--------------------------------------------------------------------------------------------------------------------*/

matrix* getGate(int gate){

    switch (gate){
        case I_GATE:
            return identity;
        case H_GATE:
            return hadamard;
        case X_GATE:
            return pauliX;
        case Y_GATE:
            return pauliY;
        case Z_GATE:
            return pauliZ;
        case S_GATE:
            return sGate;
        case T_GATE:
            return tGate;
        case SWAP_GATE:
            return swap;
        case CNOT_GATE:
            return controlledNot;
        default:
            return NULL;
    }

}

/*--------------------------------------------------------------------------------------------------------------------*/
