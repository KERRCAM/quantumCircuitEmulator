# Quantum Circuit Simulator
## Build and Run Instructions
To Build the simulator executable you will need the following dependencies:
- GCC compiler (Any supporting C99 should be fine)
- OpenMP support (Supported by most GCC versions)
- Makefile (Likely installed with GCC)
- lldb (Optional - only needed for debugging, gdb would also be fine)

You can then use the following commands to build and run the test programs:
- ```make b```: Compiles current active circuit test with src/main.c
- ```make r```: Runs active circuit test
- ```make log```: uses a local processor tool - can be found at https://github.com/KERRCAM/programPerformanceAnalysisTool
- ```make c```: Clears all executables (might have to run before building if encountering errors)
- ```make debug```: Starts a debug run with lldb of the current active circuit

##
## How to Build a Circuit
- make new c file with a main func
- include x, y, z
- init circuit
- add gates
- measure
- display
- run