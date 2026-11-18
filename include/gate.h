#ifndef GATE_H
#define GATE_H

/* LIBRARY IMPORTS */


/* LOCAL IMPORTS */

/*--------------------------------------------------------------------------------------------------------------------*/

enum gates{

    I_GATE,     /* int value = 0 */
    H_GATE,     /* int value = 1 */
    X_GATE,     /* int value = 2 */
    Y_GATE,     /* int value = 3 */
    Z_GATE,     /* int value = 4 */
    S_GATE,     /* int value = 5 */
    T_GATE,     /* int value = 6 */
    SWAP_GATE,  /* int value = 7 */
    CNOT_GATE,  /* int value = 8 */

};

/*--------------------------------------------------------------------------------------------------------------------*/

void initBaseGates(void);

matrix* getGate(int gate);

void newCustomGate(matrix* gate);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif
