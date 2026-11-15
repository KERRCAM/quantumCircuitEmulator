BUILD_DIR = builds
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_NAME = emulator
INCLUDE_PATHS = -Iinclude
COMPILER_FLAGS = -Wall -Wextra -Wall -std=c99 -fopenmp -march=native
OPT_LEVEL = -O3 # Need to be careful on this for accuracy sakes

gcc:
	gcc-15 $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME) $(OPT_LEVEL)

r:
	./$(BUILD_DIR)/$(OBJ_NAME)

c:
	rm $(BUILD_DIR)/$(OBJ_NAME)

debug:
	echo "tbd ldb cmd"
