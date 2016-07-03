OS=$(shell uname)

# LINUX OS
ifneq (,$(findstring Linux, $(OS)))

C++ := g++
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := -lsfml-graphics -lsfml-window -lsfml-system
CC_FLAGS := -std=c++14 -Werror -Wall -O3
BIN_FILE := bin/RequestedMiner
RM := rm
RMDIR := rmdir

all: directorios $(OBJ_FILES)
	$(C++) $(OBJ_FILES) -o $(BIN_FILE) $(LD_FLAGS)

obj/%.o: src/%.cpp
	$(C++) $(CC_FLAGS) -c -o $@ $<

directorios:
	if [ ! -d "obj" ]; then mkdir obj; fi
	if [ ! -d "bin" ]; then mkdir bin; fi

clean:
	$(RM) $(OBJ_FILES)

endif
