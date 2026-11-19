/* LIBRARY IMPORTS */
#include <stdio.h>
#include <stdlib.h>

/* LOCAL IMPORTS */
#include <matrix.h>
#include <gate.h>
#include <circuit.h>
#include <time.h>

/*--------------------------------------------------------------------------------------------------------------------*/

void testH(){

    circuit* qc = newCircuit(1, 1);
    H(qc, 0, 0);
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testDepth(){

    circuit* qc = newCircuit(1, 2);
    H(qc, 0, 0);
    H(qc, 0, 1);
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testQubits(){

    circuit* qc = newCircuit(2, 1);
    H(qc, 0, 0);
    H(qc, 1, 0);
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testX(){

    circuit* qc = newCircuit(1, 1);
    X(qc, 0, 0);
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testY(){

    circuit* qc = newCircuit(1, 1);
    Y(qc, 0, 0);
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testZ(){

    circuit* qc = newCircuit(1, 2);
    H(qc, 0, 0);
    Z(qc, 0, 1);
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testS(){

    circuit* qc = newCircuit(1, 2);
    H(qc, 0, 0);
    S(qc, 0, 1);
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testT(){

    circuit* qc = newCircuit(1, 2);
    H(qc, 0, 0);
    T(qc, 0, 1);
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testSwap(){

    circuit* qc = newCircuit(2, 2);
    H(qc, 0, 0);
    SWAP(qc, 0, 1, 1);
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testCNOT(){

    circuit* qc = newCircuit(2, 2);
    H(qc, 0, 0);
    CNOT(qc, 0, 1, 1);
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testGrovers(){

    circuit* qc = newCircuit(2, 2);
    // WIP
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testMaxDepth(int n){

    circuit* qc = newCircuit(1, n);
    for (int i = 0; i < n; i++){ H(qc, 0, i);}
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void testMaxQubits(int n){

    circuit* qc = newCircuit(n, 1);
    for (int i = 0; i < n; i++){ H(qc, i, 0);}
    printCircuit(qc);
    executeCircuit(qc);

}

/*--------------------------------------------------------------------------------------------------------------------*/

int main(){

    system("sudo ./ppat simulator &");
    double time, diff;
    time = (double) clock();
    time = time / CLOCKS_PER_SEC;

    initBaseGates();

    // testH();
    // testDepth();
    // testQubits();
    // testX();
    // testZ();
    // testS();
    // testT();
    // testSwap();
    // testCNOT();
    // testGrovers();
    // testMaxDepth(2000);
    testMaxQubits(15);


    // circuit* qc = newCircuit(2, 2);
    // H(qc, 0, 0);
    // SWAP(qc, 0, 1, 1);
    // printCircuit(qc);
    // executeCircuit(qc);

    diff = (((double) clock()) / CLOCKS_PER_SEC) - time;
    printf("Program run time = %lf seconds\n", diff);
    system("sudo killall powermetrics");

    return 0;

}

/*--------------------------------------------------------------------------------------------------------------------*/
