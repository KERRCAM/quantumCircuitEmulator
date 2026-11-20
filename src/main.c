/* LIBRARY IMPORTS */
#include <stdio.h>
#include <stdlib.h>

/* LOCAL IMPORTS */
#include <matrix.h>
#include <gate.h>
#include <circuit.h>
#include <omp.h>

/*--------------------------------------------------------------------------------------------------------------------*/

void testH(){

    circuit* qc = newCircuit(1, 1);
    H(qc, 0, 0);
    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testDepth(){

    circuit* qc = newCircuit(1, 2);
    H(qc, 0, 0);
    H(qc, 0, 1);
    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testQubits(){

    circuit* qc = newCircuit(2, 1);
    H(qc, 0, 0);
    H(qc, 1, 0);
    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testX(){

    circuit* qc = newCircuit(1, 1);
    X(qc, 0, 0);
    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testY(){

    circuit* qc = newCircuit(1, 1);
    Y(qc, 0, 0);
    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testZ(){

    circuit* qc = newCircuit(1, 2);
    H(qc, 0, 0);
    Z(qc, 0, 1);
    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testS(){

    circuit* qc = newCircuit(1, 2);
    H(qc, 0, 0);
    S(qc, 0, 1);
    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testT(){

    circuit* qc = newCircuit(1, 2);
    H(qc, 0, 0);
    T(qc, 0, 1);
    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testSwap(){

    circuit* qc = newCircuit(2, 2);
    H(qc, 0, 0);
    SWAP(qc, 0, 1, 1);
    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testCNOT(){

    circuit* qc = newCircuit(2, 2);
    H(qc, 0, 0);
    CNOT(qc, 0, 1, 1);
    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testGrovers(){

    circuit* qc = newCircuit(2, 9);

    H(qc, 0, 0);
    H(qc, 1, 0);
    CZ(qc, 0, 1, 1);
    H(qc, 0, 2);
    H(qc, 1, 2);
    X(qc, 0, 3);
    X(qc, 1, 3);
    H(qc, 1, 4);
    CNOT(qc, 0, 1, 5);
    X(qc, 0, 6);
    H(qc, 1, 6);
    H(qc, 0, 7);
    X(qc, 1, 7);
    H(qc, 1, 8);

    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testMaxDepth(int n){

    circuit* qc = newCircuit(1, n);
    for (int i = 0; i < n; i++){ H(qc, 0, i);}
    printCircuit(qc);
    executeCircuit(qc);
    printStateVector(qc);
    printCircuitMatrix(qc);
    printProbabilities(qc);
    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testMaxQubits(int n){

    // system("sudo ./ppat simulator &");
    double start = omp_get_wtime();

    circuit* qc = newCircuit(n, 1);
    for (int i = 0; i < n; i++){ H(qc, i, 0);}
    printCircuit(qc);
    executeCircuit(qc);
    // printStateVector(qc);
    // printCircuitMatrix(qc);
    // printProbabilities(qc);

    printf("Program run time (%d threads) = %lf seconds\n", omp_get_max_threads(), omp_get_wtime() - start);
    // system("sudo killall powermetrics");

    printf("\n#---------------------------------------------------------------------------------------------------#\n");

}

/*--------------------------------------------------------------------------------------------------------------------*/

int main(){

    initBaseGates();

    // testH();
    // testDepth();
    // testQubits();
    // testX();
    // testY();
    // testZ();
    // testS();
    // testT();
    // testSwap();
    // testCNOT();
    // testGrovers();
    // testMaxDepth(2000);
    testMaxQubits(15);

    return 0;

}

/*--------------------------------------------------------------------------------------------------------------------*/
