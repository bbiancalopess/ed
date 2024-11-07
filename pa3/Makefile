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
test: all
	./$(TARGET) -a fii -v 1
	./$(TARGET) -a fii -v 2
	./$(TARGET) -a fii -v 3
	./$(TARGET) -a fii -v 4
	./$(TARGET) -a fii -v 5
	./$(TARGET) -a fii -v 6
	./$(TARGET) -a fii -v 7
	./$(TARGET) -a fii -v 8
	./$(TARGET) -a fii -v 9
	./$(TARGET) -a fii -v 10
	./$(TARGET) -a fii -v 11
	./$(TARGET) -a fii -v 12
	./$(TARGET) -a fii -v 13
	./$(TARGET) -a fii -v 14
	./$(TARGET) -a fii -v 15
	./$(TARGET) -a fii -v 16
	./$(TARGET) -a fii -v 17
	./$(TARGET) -a fii -v 18
	./$(TARGET) -a fii -v 19
	./$(TARGET) -a fii -v 20
	./$(TARGET) -a fii -v 21
	./$(TARGET) -a fii -v 22
	./$(TARGET) -a fii -v 23
	./$(TARGET) -a fii -v 24
	./$(TARGET) -a fii -v 25
	./$(TARGET) -a fii -v 26
	./$(TARGET) -a fii -v 27
	./$(TARGET) -a fii -v 28
	./$(TARGET) -a fii -v 29
	./$(TARGET) -a fii -v 30
	./$(TARGET) -a fii -v 31
	./$(TARGET) -a fii -v 32
	./$(TARGET) -a fii -v 33
	./$(TARGET) -a fii -v 34
	./$(TARGET) -a fii -v 35
	./$(TARGET) -a fii -v 36
	./$(TARGET) -a fii -v 37
	./$(TARGET) -a fii -v 38
	./$(TARGET) -a fii -v 39
	./$(TARGET) -a fii -v 40
	./$(TARGET) -a fir -v 1
	./$(TARGET) -a fir -v 2
	./$(TARGET) -a fir -v 3
	./$(TARGET) -a fir -v 4
	./$(TARGET) -a fir -v 5
	./$(TARGET) -a fir -v 6
	./$(TARGET) -a fir -v 7
	./$(TARGET) -a fir -v 8
	./$(TARGET) -a fir -v 9
	./$(TARGET) -a fir -v 10
	./$(TARGET) -a fir -v 11
	./$(TARGET) -a fir -v 12
	./$(TARGET) -a fir -v 13
	./$(TARGET) -a fir -v 14
	./$(TARGET) -a fir -v 15
	./$(TARGET) -a fir -v 16
	./$(TARGET) -a fir -v 17
	./$(TARGET) -a fir -v 18
	./$(TARGET) -a fir -v 19
	./$(TARGET) -a fir -v 20
	./$(TARGET) -a fir -v 21
	./$(TARGET) -a fir -v 22
	./$(TARGET) -a fir -v 23
	./$(TARGET) -a fir -v 24
	./$(TARGET) -a fir -v 25
	./$(TARGET) -a fir -v 26
	./$(TARGET) -a fir -v 27
	./$(TARGET) -a fir -v 28
	./$(TARGET) -a fir -v 29
	./$(TARGET) -a fir -v 30
	./$(TARGET) -a fir -v 31
	./$(TARGET) -a fir -v 32
	./$(TARGET) -a fir -v 33
	./$(TARGET) -a fir -v 34
	./$(TARGET) -a fir -v 35
	./$(TARGET) -a fir -v 36
	./$(TARGET) -a fir -v 37
	./$(TARGET) -a fir -v 38
	./$(TARGET) -a fir -v 39
	./$(TARGET) -a fir -v 40
	./$(TARGET) -a fai -v 1
	./$(TARGET) -a fai -v 2
	./$(TARGET) -a fai -v 3
	./$(TARGET) -a fai -v 4
	./$(TARGET) -a fai -v 5
	./$(TARGET) -a fai -v 6
	./$(TARGET) -a fai -v 7
	./$(TARGET) -a fai -v 8
	./$(TARGET) -a fai -v 9
	./$(TARGET) -a fai -v 10
	./$(TARGET) -a fai -v 11
	./$(TARGET) -a fai -v 12
	./$(TARGET) -a fai -v 13
	./$(TARGET) -a fai -v 14
	./$(TARGET) -a fai -v 15
	./$(TARGET) -a fai -v 16
	./$(TARGET) -a fai -v 17
	./$(TARGET) -a fai -v 18
	./$(TARGET) -a fai -v 19
	./$(TARGET) -a fai -v 20
	./$(TARGET) -a far -v 1
	./$(TARGET) -a far -v 2
	./$(TARGET) -a far -v 3
	./$(TARGET) -a far -v 4
	./$(TARGET) -a far -v 5
	./$(TARGET) -a far -v 6
	./$(TARGET) -a far -v 7
	./$(TARGET) -a far -v 8
	./$(TARGET) -a far -v 9
	./$(TARGET) -a far -v 10
	./$(TARGET) -a far -v 11
	./$(TARGET) -a far -v 12
	./$(TARGET) -a far -v 13
	./$(TARGET) -a far -v 14
	./$(TARGET) -a far -v 15
	./$(TARGET) -a far -v 16
	./$(TARGET) -a far -v 17
	./$(TARGET) -a far -v 18
	./$(TARGET) -a far -v 19
	./$(TARGET) -a far -v 20