/* LIBRARY IMPORTS */
#include <stdlib.h>

/* LOCAL IMPORTS */
#include <circuit.h>
#include <gate.h>

/*--------------------------------------------------------------------------------------------------------------------*/

circuit* newCircuit(short int noq, short int depth){

    /* Memory allocation */
    circuit* c = calloc(1, sizeof(*c));

    /* Initialising attributes */
    c->noq = noq;
    c->depth = depth;
    c->gates = calloc(1, sizeof(int) * noq * depth);
    c->stateVector = NULL;

    return c;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void H(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    printf("%d\n", c->gates[index]);
    if (c->gates[index] == 0){ c->gates[index] = H_GATE;}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void X(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    if (c->gates[index] == 0){ c->gates[index] = X_GATE;}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void Y(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    if (c->gates[index] == 0){ c->gates[index] = Y_GATE;}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void Z(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    if (c->gates[index] == 0){ c->gates[index] = Z_GATE;}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void S(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    if (c->gates[index] == 0){ c->gates[index] = S_GATE;}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void T(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    if (c->gates[index] == 0){ c->gates[index] = T_GATE;}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void SWAP(circuit* c, int control, int target, int depth){

    if (control > c->noq || target > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int controlIndex = control * c->depth + depth;
    int targetIndex = target * c->depth + depth;
    if (c->gates[controlIndex] != 0 && c->gates[targetIndex] != 0){
        c->gates[controlIndex] = SWAP_GATE; c->gates[targetIndex] = SWAP_GATE;
    } else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void CNOT(circuit* c, int control, int target, int depth){

    if (control > c->noq || target > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int controlIndex = control * c->depth + depth;
    int targetIndex = target * c->depth + depth;
    if (c->gates[controlIndex] != 0 && c->gates[targetIndex] != 0){
        c->gates[controlIndex] = CNOT_GATE; c->gates[targetIndex] = CNOT_GATE;
    } else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void executeCircuit(circuit* c){

    matrix* basis = newMatrix(2, 1);
    basis->mat[0] = 1.0;
    c->stateVector = basis;
    for (int q = 1; q < c->noq; q++){c->stateVector = tensorProduct(c->stateVector, basis);}

    for (int d = 0; d < c->depth; d++){

        matrix* layer = getGate(c->gates[d]);

        for (int q = 1; q < c->noq; q++){

            layer = tensorProduct(layer, getGate(c->gates[q * c->depth + d]));

        }

        c->stateVector = matrixMult(layer, c->stateVector);

    }

    printMatrix(c->stateVector);

}

/*--------------------------------------------------------------------------------------------------------------------*/
