# Nome do compilador
COMPILADOR = g++

# Nome do executável
TARGET = pa1.out

# Flags de compilação
COMP_FLAGS = -Iinclude -Wall -std=c++11

# Lista de arquivos fontes
SOURCES = main.cpp utils.cpp performance.cpp algorithms.cpp args.cpp

# Geração dos arquivos objetos
OBJECTS = $(SOURCES:.cpp=.o)

# Regra padrão para compilar e linkar o projeto
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJECTS)
	$(COMPILADOR) $(OBJECTS) -o $(TARGET)

# Regra para gerar os arquivos objeto
.o: .cpp
	$(COMPILADOR) $(COMP_FLAGS) -c $< -o $@

# Comando para limpar os arquivos objeto e do executável
clean:
	rm -rf $(OBJECTS) $(TARGET)

# Comando para rodar o programa
run: all
	./$(TARGET)
