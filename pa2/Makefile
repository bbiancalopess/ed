COMPILADOR = gcc
COMPFLAGS = -Iinclude -Wall
TARGET = bin/pa1.out

# Lista de arquivos fontes
SRCS = $(wildcard src/*.c)

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
	$(COMPILADOR) $(COMPFLAGS) -c $< -o $@

# Garante que o diretório obj exista
obj:
	@mkdir -p obj

# Comando para limpar os arquivos objeto e do executável
clean:
	rm -rf obj/*.o $(TARGET)

# Comando para rodar testes
test: all
	./$(TARGET) -z 9 -s 27 -a q3
	./$(TARGET) -z 81 -s 17 -a q3
	./$(TARGET) -z 448 -s 15 -a q3
	./$(TARGET) -z 4803 -s 34 -a q3
	./$(TARGET) -z 19097 -s 25 -a q3
	./$(TARGET) -z 9 -s 27 -a q3i
	./$(TARGET) -z 81 -s 17 -a q3i
	./$(TARGET) -z 448 -s 15 -a q3i
	./$(TARGET) -z 4803 -s 34 -a q3i
	./$(TARGET) -z 19097 -s 25 -a q3i
	
	
