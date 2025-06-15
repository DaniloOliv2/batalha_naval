# Nome do executável
EXEC = batalha_naval

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -pedantic

# Arquivos objeto
OBJ = main.o jogo.o arquivo.o

# Regra padrão
all: $(EXEC)

# Como gerar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Como gerar os arquivos objeto
main.o: main.c jogo.h arquivo.h
	$(CC) $(CFLAGS) -c main.c

jogo.o: jogo.c jogo.h
	$(CC) $(CFLAGS) -c jogo.c

arquivo.o: arquivo.c arquivo.h jogo.h
	$(CC) $(CFLAGS) -c arquivo.c

# Comando para limpar os arquivos objeto e executável
clean:
	del *.o $(EXEC) 2>nul || rm -f *.o $(EXEC)

