#ifndef JOGO_H
#define JOGO_H

#define TAMANHO 10
#define NAVIOS 5

// Funções do jogo
void inicializarTabuleiros(int jogador[TAMANHO][TAMANHO], int inimigo[TAMANHO][TAMANHO]);
void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]);
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO], int exibirNavios);
void jogar(int jogador[TAMANHO][TAMANHO], int inimigo[TAMANHO][TAMANHO]);

#endif
