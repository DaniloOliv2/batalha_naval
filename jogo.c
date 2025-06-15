#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"

void inicializarTabuleiros(int jogador[TAMANHO][TAMANHO], int inimigo[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            jogador[i][j] = 0;
            inimigo[i][j] = 0;
        }
    }
}

void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    srand(time(NULL));
    int naviosColocados = 0;

    while (naviosColocados < NAVIOS) {
        int linha = rand() % TAMANHO;
        int coluna = rand() % TAMANHO;

        if (tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = 1;
            naviosColocados++;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO], int exibirNavios) {
    printf("\n  ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d|", i);
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ ");
            } else if (tabuleiro[i][j] == 1) {
                printf("%s ", exibirNavios ? "N" : "~");
            } else if (tabuleiro[i][j] == 2) {
                printf("X ");
            } else if (tabuleiro[i][j] == 3) {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void jogar(int jogador[TAMANHO][TAMANHO], int inimigo[TAMANHO][TAMANHO]) {
    int linha, coluna;
    int naviosRestantes = NAVIOS;

    while (naviosRestantes > 0) {
        exibirTabuleiro(jogador, 1);
        printf("\nInforme linha e coluna para atacar (Ex: 3 4): ");
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
            printf("Posicao invalida. Tente novamente.\n");
            continue;
        }

        if (inimigo[linha][coluna] == 1) {
            printf("Acertou um navio!\n");
            jogador[linha][coluna] = 2;
            inimigo[linha][coluna] = 2;
            naviosRestantes--;
        } else if (jogador[linha][coluna] == 2 || jogador[linha][coluna] == 3) {
            printf("Voce ja atacou essa posicao. Tente outra.\n");
        } else {
            printf("Errou!\n");
            jogador[linha][coluna] = 3;
        }
    }

    printf("\nParabens! Voce destruiu todos os navios!\n");
}
