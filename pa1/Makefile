COMPILADOR = g++
COMP_FLAGS = -Iinclude -Wall -std=c++11
SOURCES_DIR = src
OBJECTS_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/matop

SOURCES = $(SOURCES_DIR)/mat.cpp $(SOURCES_DIR)/matop.cpp

OBJECTS = $(OBJECTS_DIR)/mat.o $(OBJECTS_DIR)/matop.o

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(COMPILADOR) $(COMP_FLAGS) -o $@ $^

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp | $(OBJECTS_DIR)
	$(COMPILADOR) $(COMP_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_DIR)/*.o $(TARGET)

run: all
	./$(TARGET) -s -x 5 -y 5
	./$(TARGET) -m -x 5 -y 5
	./$(TARGET) -t -x 5 -y 5
