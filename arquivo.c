#include <stdio.h>
#include "jogo.h"
#include "arquivo.h"

void salvarJogo(int jogador[TAMANHO][TAMANHO], int inimigo[TAMANHO][TAMANHO]) {
    FILE *file = fopen("salvar_partida.txt", "w");
    if (file == NULL) {
        printf("Erro ao salvar o jogo!\n");
        return;
    }

    // Salvar tabuleiro do jogador
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            fprintf(file, "%d ", jogador[i][j]);
        }
        fprintf(file, "\n");
    }

    // Salvar tabuleiro do inimigo
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            fprintf(file, "%d ", inimigo[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Jogo salvo com sucesso!\n");
}

void carregarJogo(int jogador[TAMANHO][TAMANHO], int inimigo[TAMANHO][TAMANHO]) {
    FILE *file = fopen("salvar_partida.txt", "r");
    if (file == NULL) {
        printf("Nenhum jogo salvo encontrado!\n");
        return;
    }

    // Carregar tabuleiro do jogador
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            fscanf(file, "%d", &jogador[i][j]);
        }
    }

    // Carregar tabuleiro do inimigo
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            fscanf(file, "%d", &inimigo[i][j]);
        }
    }

    fclose(file);
    printf("Jogo carregado com sucesso!\n");
}
