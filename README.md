# Quantum Circuit Simulator
## Build and Run Instructions
To Build the simulator executable you will need the following dependencies:
- GCC compiler (Any supporting C99 should be fine)
- OpenMP support (Supported by most GCC versions)
- Makefile (Likely installed with GCC)
- lldb (Optional - only needed for debugging, gdb would also be fine)

You can then use the following commands to build and run the test programs:
- ```make b```: Compiles current active circuit test with src/main.c
- ```make r```: Runs the simulator
- ```make log```: uses a local processor tool - can be found at https://github.com/KERRCAM/programPerformanceAnalysisTool
- ```make c```: Clears all executables (might have to run before building if encountering errors)
- ```make debug```: Starts a debug run with lldb of the current active circuit

Note the MakeFile instructions specify gcc-15, you will likely have to change this to gcc or whatever version you are using. <br/>

##
## Running the test circuits
When you download the code, the src/main.c file contains all tests used to verify teh correctness of the simulator. <br/>
In the main function the calls to all these tests should be uncommented and so you can run them all with make r after  <br/>
you have compiled the code. <br/>


##
## How to Build a Circuit
If you look at the test function in src/main.c you can see examples of how circuits are built. <br/>
To start if you were making a new main file you would need to include the key headers: <br/>
```c
#include <matrix.h>
#include <gate.h>
#include <circuit.h>
```

To initialise the gates you can then call the function ```initBaseGates();```. This is needed to build the <br/>
gates used in our circuits. From here you can make a new circuit struct and add gates. Below is an example <br/>
of building a simple bell state with a hadamard gate an a CNOT gate. <br/>
```c++
    circuit* qc = newCircuit(2, 2);
    H(qc, 0, 0);
    CNOT(qc, 0, 1, 1);
```

First we make a new circuit struct with ```circuit* name = newCircuit(numberOfQubits, circuitDepth);``` <br/>
We then call our gate functions with the circuit struct, the qubit(s) we want to place the gate on and the depth <br/>
we want the gate in the circuit. An error will be produced if you try to place gates over the top of each other. <br/>
Once we have built our circuit we can print it out with ```printCircuit(qc);``` to check our result: <br/>

```c++
printCircuit(qc);

    ^v

q0: -- H  -- CX --
q1: -- I  -- TG --
```

We can see each qubit is printed out one below another with the gates level at each depth point in the circuit. <br/>
In this example, H is our Hadamard gate, I is an identity gate (these fill in any unspecified positions) and lastly <br/>
CX is our control gate for our CNOT with TG being our target. <br/>

Now we have built and confirmed our circuit we can execute teh circuit an print some results with the following functions: <br/>

```c++
executeCircuit(qc);

    ^v

executes our circuit
```
```c++
printStateVector(qc);

    ^v

STATE VECTOR:
[ 0.707107 +0.000000i ]
[ 0.000000 +0.000000i ]
[ 0.000000 +0.000000i ]
[ 0.707107 +0.000000i ]
```
```c++
printCircuitMatrix(qc);

    ^v

CIRCUIT MATRIX:
[ 0.707107 +0.000000i, 0.707107 +0.000000i, 0.000000 +0.000000i, 0.000000 +0.000000i ]
[ 0.000000 +0.000000i, 0.000000 +0.000000i, 0.707107 +0.000000i, -0.707107 +0.000000i ]
[ 0.000000 +0.000000i, 0.000000 +0.000000i, 0.707107 +0.000000i, 0.707107 +0.000000i ]
[ 0.707107 +0.000000i, -0.707107 +0.000000i, 0.000000 +0.000000i, 0.000000 +0.000000i ]
```
```c++
printProbabilities(qc);

    ^v

STATE PROBABILITIES:
|0>: 0.500000 +0.000000i
|1>: 0.000000 +0.000000i
|2>: 0.000000 +0.000000i
|3>: 0.500000 +0.000000i
```
