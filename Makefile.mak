#filenames of main, classes to be compiled, and output:
MAIN = main.cc
OBJECTS = user.o message.o bulletin_board.o topic.o reply.of
OUT = bulletin_board

#Compile components:
CXX = g++
FLAGS = -W -Wall -pedantic -ansi -Werror
CXXFLAGS = -g $(FLAGS)
COMPFLAGS = -c $(FLAGS)

# The basic compile command:
COMPILE = $(CXX) $(CXXFLAGS)
COMPILE_ONLY = $(CXX) $(COMPFLAGS)

# Compile
all: $(OBJECTS)
	$(COMPILE) $(MAIN) $(OBJECTS) -o $(OUT)

user.o: user.h user.cc
	$(COMPILE_ONLY) user.cc
	
message.o: message.h message.cc
	$(COMPILE_ONLY) message.cc
	
bulletin_board.o: bulletin_board.h bulletin_board.cc user.h message.h reply.h topic.h
	$(COMPILE_ONLY) bulletin_board.cc
	
topic.o: topic.h topic.cc message.h
	$(COMPILE_ONLY) topic.cc
	
reply.o: reply.h reply.cc message.h
	$(COMPILE_ONLY) reply.cc
	
clean:
	rm -rf *.exe *.o *~ $(OUT)