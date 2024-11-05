# Makefile para compilar os programas teste_MPU e teste_pilhampu

# Nomes dos executáveis
TARGET1 = teste_MPU
TARGET2 = teste_pilhampu

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Arquivos fonte
SRC1 = teste_MPU.c mpuTAD.c
SRC2 = teste_pilhampu.c mpuTAD.c pilhampuTAD.c

# Objetos
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

# Regras para compilar todos os executáveis
all: $(TARGET1) $(TARGET2)

# Compilar o primeiro programa (teste_MPU)
$(TARGET1): $(OBJ1)
	$(CC) $(OBJ1) -o $(TARGET1)

# Compilar o segundo programa (teste_pilhampu)
$(TARGET2): $(OBJ2)
	$(CC) $(OBJ2) -o $(TARGET2)

# Regras para compilar cada arquivo .c em .o (automático para cada .c encontrado)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -f $(OBJ1) $(OBJ2) $(TARGET1) $(TARGET2)

# Executar o primeiro programa (teste_MPU)
run1: $(TARGET1)
	./$(TARGET1)

# Executar o segundo programa (teste_pilhampu)
run2: $(TARGET2)
	./$(TARGET2)
