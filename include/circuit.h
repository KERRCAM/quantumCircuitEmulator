#ifndef CIRCUIT_H
#define CIRCUIT_H

/* LIBRARY IMPORTS */


/* LOCAL IMPORTS */
#include <matrix.h>

/*--------------------------------------------------------------------------------------------------------------------*/

typedef struct CIRCUIT_STRUCT{

    short int noq;
    short int depth;
    matrix* gates;
    matrix** qubits;
    matrix* stateVector;

} circuit;

/*--------------------------------------------------------------------------------------------------------------------*/

circuit* newCircuit(short int noq, short int depth);

void executeCircuit();

void printStateVector(circuit* c);

void printMeasurementResult(circuit* c);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif
