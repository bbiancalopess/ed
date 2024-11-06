COMPILADOR = gcc
COMPFLAGS = -Iinclude -Wall
TARGET = bin/mathOps

# Lista de arquivos fontes
SRCS = $(wildcard src/*.c)

# Geração dos arquivos objetos
OBJS = $(SRCS:src/%.c=obj/%.o)

# Regra padrão para compilar e linkar o projeto
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	@mkdir -p bin
	$(COMPILADOR) $(COMPFLAGS) $(OBJS) -o $(TARGET)

# Regra para gerar os arquivos objeto
obj/%.o: src/%.c | obj
	$(COMPILADOR) $(COMPFLAGS) -c $< -o $@

# Garante que o diretório obj exista
obj:
	@mkdir -p obj

# Comando para limpar os arquivos objeto e do executável
clean:
	rm -rf obj/*.o $(TARGET)

# Comando para rodar testes
#test: all
	
	
