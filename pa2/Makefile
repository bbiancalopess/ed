COMPILADOR = g++
COMP_FLAGS = -Iinclude -Wall -std=c++11
TARGET = pa1.out

SOURCES = utils.cpp performance.cpp algorithms.cpp args.cpp main.cpp

OBJECTS = utils.o performance.o algorithms.o args.o main.o

all: $(TARGET)

$(TARGET): $(OBJECTS) 
	$(COMPILADOR) $(COMP_FLAGS) -o $@ $^

%.o: %.cpp 
	$(COMPILADOR) $(COMP_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)

run: all
	./$(TARGET)
