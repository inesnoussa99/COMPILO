include config-wsl-2025.mk

CC=g++
CCFLAGS=-g -c -std=c++17 -I$(ANTLRINC) -Igenerated/ -Wno-attributes 
LDFLAGS=-g

default: all
all: ifcc

OBJECTS=build/ifccBaseVisitor.o \
	build/ifccLexer.o \
	build/ifccVisitor.o \
	build/ifccParser.o \
	build/main.o \
	build/StaticVisitor.o \
	build/CodeGenVisitor.o \
	build/IR.o

ifcc: $(OBJECTS)
	@mkdir -p build
	$(CC) $(LDFLAGS) build/*.o $(ANTLRLIB) -o ifcc

build/%.o: %.cpp generated/ifccParser.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $< 

build/%.o: generated/%.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $< 

-include build/*.d

##########################################
generated/ifccParser.cpp: ifcc.g4
	@mkdir -p generated
	java -jar $(ANTLRJAR) -visitor -no-listener -Dlanguage=Cpp -o generated ifcc.g4

generated/ifccLexer.cpp: generated/ifccParser.cpp
generated/ifccVisitor.cpp: generated/ifccParser.cpp
generated/ifccBaseVisitor.cpp: generated/ifccParser.cpp

.PRECIOUS: generated/ifcc%.cpp   

clean:
	rm -rf build generated
	rm -f ifcc