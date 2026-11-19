/* LIBRARY IMPORTS */
#include <stdlib.h>

/* LOCAL IMPORTS */
#include <circuit.h>
#include <gate.h>


const char* gateStrings[] = {

    " TG ",     /* int value =-1 */
    " I  ",     /* int value = 0 */
    " H  ",     /* int value = 1 */
    " X  ",     /* int value = 2 */
    " Y  ",     /* int value = 3 */
    " Z  ",     /* int value = 4 */
    " S  ",     /* int value = 5 */
    " T  ",     /* int value = 6 */
    " SP ",     /* int value = 7 */
    " CX ",     /* int value = 8 */
    " CZ ",     /* int value = 9 */

};

/*--------------------------------------------------------------------------------------------------------------------*/

circuit* newCircuit(short int noq, short int depth){

    /* Memory allocation */
    circuit* c = calloc(1, sizeof(*c));

    /* Initialising attributes */
    c->noq = noq;
    c->depth = depth;
    c->gates = calloc(1, sizeof(gate) * noq * depth);
    c->stateVector = NULL;

    return c;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void H(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    if (c->gates[index].tag == 0){ c->gates[index] = newGate(H_GATE, index, -1);}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void X(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    if (c->gates[index].tag == 0){ c->gates[index] = newGate(X_GATE, index, -1);}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void Y(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    if (c->gates[index].tag == 0){ c->gates[index] = newGate(Y_GATE, index, -1);}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void Z(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    if (c->gates[index].tag == 0){ c->gates[index] = newGate(Z_GATE, index, -1);}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void S(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    if (c->gates[index].tag == 0){ c->gates[index] = newGate(S_GATE, index, -1);}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void T(circuit* c, int qubit, int depth){

    if (qubit > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int index = qubit * c->depth + depth;
    if (c->gates[index].tag == 0){ c->gates[index] = newGate(T_GATE, index, -1);}
    else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void SWAP(circuit* c, int control, int target, int depth){

    if (control > c->noq || target > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int controlIndex = control * c->depth + depth;
    int targetIndex = target * c->depth + depth;
    if (c->gates[controlIndex].tag == 0 && c->gates[targetIndex].tag == 0){
        c->gates[controlIndex] = newGate(SWAP_GATE, controlIndex, targetIndex);
        c->gates[targetIndex] = newGate(-1, -1, -1);
    } else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void CNOT(circuit* c, int control, int target, int depth){

    if (control > c->noq || target > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int controlIndex = control * c->depth + depth;
    int targetIndex = target * c->depth + depth;
    if (c->gates[controlIndex].tag == 0 && c->gates[targetIndex].tag == 0){
        c->gates[controlIndex] = newGate(CNOT_GATE, controlIndex, targetIndex);
        c->gates[targetIndex] = newGate(-1, -1, -1);
    } else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void CZ(circuit* c, int control, int target, int depth){

    if (control > c->noq || target > c->noq){ printf("WARNING: Qubit index outside of range of circuit\n"); return;}
    if (depth > c->depth){ printf("WARNING: Depth index outside of range of circuit\n"); return;}

    int controlIndex = control * c->depth + depth;
    int targetIndex = target * c->depth + depth;
    if (c->gates[controlIndex].tag == 0 && c->gates[targetIndex].tag == 0){
        c->gates[controlIndex] = newGate(CZ_GATE, controlIndex, targetIndex);
        c->gates[targetIndex] = newGate(-1, -1, -1);
    } else { printf("WARNING: Already assigned a gate to this position\n");}

}

/*--------------------------------------------------------------------------------------------------------------------*/

void executeCircuit(circuit* c){

    matrix* basis = newMatrix(2, 1);
    basis->mat[0] = 1.0;
    c->stateVector = basis;
    for (int q = 1; q < c->noq; q++){c->stateVector = tensorProduct(c->stateVector, basis);}

    matrix* cr = NULL;

    for (int d = c->depth - 1; d >= 0; d--){

        matrix* layer = NULL;

        for (int q = c->noq - 1; q >= 0; q--){
            if (c->gates[q * c->depth + d].tag != -1){
                if (layer == NULL){ layer = getGate(c->gates[q * c->depth + d].tag);}
                else { layer = tensorProduct(layer, getGate(c->gates[q * c->depth + d].tag));}
            }
        }

        if (d == c->depth - 1){ cr = layer;}
        else { cr = matrixMult(cr, layer);}

        /* Depth by depth matrix representation of circuit and state vector updates for debugging */
        // printf("Cr\n");
        // printMatrix(cr);
        // printf("\n\n");
        // printf("running\n");
        // printMatrix(matrixMult(cr, c->stateVector));
        // printf("\n\n");

    }

    c->stateVector = matrixMult(cr, c->stateVector);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void printCircuit(circuit* c){

    printf("CIRCUIT DIAGRAM:\n");

    for (int q = 0; q < c->noq; q++){
        printf("q%d: --", q);
        for (int d = 0; d < c->depth; d++){
            printf("%s--", gateStrings[c->gates[q * c->depth + d].tag + 1]);
        }
        printf("\n");
    }

    printf("\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void printStateVector(circuit* c){

    printf("STATE VECTOR:\n");
    printMatrix(c->stateVector);

}

/*--------------------------------------------------------------------------------------------------------------------*/
