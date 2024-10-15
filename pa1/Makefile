# Nome do compilador
COMPILADOR = g++

# Nome do executável
TARGET = bin/matop

# Flags de compilação
COMP_FLAGS = -Iinclude -Wall -std=c++11

# Lista de arquivos fontes
SOURCES = $(wildcard src/*.cpp)

# Geração dos arquivos objetos
OBJECTS = $(SOURCES:src/%.cpp=obj/%.o)

# Regra padrão para compilar e linkar o projeto
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJECTS)
	@mkdir -p bin
	$(COMPILADOR) $(OBJECTS) -o $(TARGET)

# Regra para gerar os arquivos objeto
obj/%.o: src/%.cpp
	@mkdir -p obj
	$(COMPILADOR) $(COMP_FLAGS) -c $< -o $@

# Comando para limpar os arquivos objeto e do executável
clean:
	rm -rf obj/*.o $(TARGET)

# Comando para rodar o programa
run: all
	./$(TARGET) -s -x 5 -y 5
	./$(TARGET) -m -x 5 -y 5
	./$(TARGET) -t -x 5 -y 5
