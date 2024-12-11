COMPILADOR = g++
COMPFLAGS = -Iinclude -Wall -pg -g
TARGET = bin/pa3.out

# Lista de arquivos fontes
SRCS = $(wildcard src/*.cpp)

# Geração dos arquivos objetos
OBJS = $(SRCS:src/%.cpp=obj/%.o)

# Regra padrão para compilar e linkar o projeto
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	@mkdir -p bin
	$(COMPILADOR) $(COMPFLAGS) $(OBJS) -o $(TARGET)

# Regra para gerar os arquivos objeto
obj/%.o: src/%.cpp | obj
	@mkdir -p obj
	$(COMPILADOR) $(COMPFLAGS) -c $< -o $@

# Garante que o diretório obj exista
obj:
	@mkdir -p obj

# Comando para limpar os arquivos objeto e do executável
clean:
	rm -rf obj/*.o $(TARGET)

run: all
	./$(TARGET)