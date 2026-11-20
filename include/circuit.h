#ifndef CIRCUIT_H
#define CIRCUIT_H

/* LIBRARY IMPORTS */


/* LOCAL IMPORTS */
#include <matrix.h>
#include <gate.h>

/*--------------------------------------------------------------------------------------------------------------------*/

typedef struct CIRCUIT_STRUCT{

    short int noq;  /* Number of qubits */
    short int depth;
    gate* gates;
    matrix* stateVector;
    matrix* circuitMatrix;

} circuit;

/*--------------------------------------------------------------------------------------------------------------------*/

void printCircuit(circuit* c);

circuit* newCircuit(short int noq, short int depth);

void setQubitBasis(circuit* c, int qubit);

void H(circuit* c, int qubit, int depth);

void X(circuit* c, int qubit, int depth);

void Y(circuit* c, int qubit, int depth);

void Z(circuit* c, int qubit, int depth);

void S(circuit* c, int qubit, int depth);

void T(circuit* c, int qubit, int depth);

void SWAP(circuit* c, int control, int target, int depth);

void CNOT(circuit* c, int control, int target, int depth);

void CZ(circuit* c, int control, int target, int depth);

void executeCircuit(circuit* c);

void printStateVector(circuit* c);

void printCircuitMatrix(circuit* c);

void printProbabilities(circuit* c);

void printMeasurementResult(circuit* c);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif
