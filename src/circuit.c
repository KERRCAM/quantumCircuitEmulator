/* LIBRARY IMPORTS */
#include <stdlib.h>

/* LOCAL IMPORTS */
#include <circuit.h>

/*--------------------------------------------------------------------------------------------------------------------*/

circuit* newCircuit(short int noq, short int depth){

    /* Memory allocation */
    circuit* c = calloc(1, sizeof(*c));

    /* Initialising attributes */
    c->noq = noq;
    c->depth = depth;
    c->gates = newMatrix(noq, depth);
    c->qubits = calloc(1, sizeof(matrix*) * noq);
    c->stateVector = NULL;

    return c;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void executeCircuit(){}

/*--------------------------------------------------------------------------------------------------------------------*/
