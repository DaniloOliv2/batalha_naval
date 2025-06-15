#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "jogo.h"

// Funções para salvar e carregar o jogo
void salvarJogo(int jogador[TAMANHO][TAMANHO], int inimigo[TAMANHO][TAMANHO]);
void carregarJogo(int jogador[TAMANHO][TAMANHO], int inimigo[TAMANHO][TAMANHO]);

#endif