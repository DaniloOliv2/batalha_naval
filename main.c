#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definições
#define TAM 10         // Tamanho do tabuleiro (10x10)
#define NUM_NAVIOS 5   // Quantidade de navios no jogo

// Função para inicializar o tabuleiro com '~' (água)
void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~';
        }
    }
}

// Função para posicionar os navios aleatoriamente
void posicionarNavios(char tabuleiro[TAM][TAM]) {
    int naviosPosicionados = 0;
    while (naviosPosicionados < NUM_NAVIOS) {
        int linha = rand() % TAM;
        int coluna = rand() % TAM;

        if (tabuleiro[linha][coluna] == '~') {
            tabuleiro[linha][coluna] = 'N'; // 'N' representa um navio (oculto durante o jogo)
            naviosPosicionados++;
        }
    }
}

// Função para exibir o tabuleiro
// Se mostrarNavios == 1, mostra os navios no final do jogo
void exibirTabuleiro(char tabuleiro[TAM][TAM], int mostrarNavios) {
    printf("\n   ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d |", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 'N' && !mostrarNavios) {
                printf("~ ");
            } else {
                printf("%c ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

// Função principal
int main() {
    char tabuleiro[TAM][TAM];
    int linha, coluna;
    int acertos = 0;

    srand(time(NULL)); // Semente aleatória

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    printf("==========================================\n");
    printf("        🚢 JOGO DE BATALHA NAVAL 🚢       \n");
    printf("==========================================\n");
    printf("Objetivo: Encontrar e destruir os %d navios.\n", NUM_NAVIOS);

    while (acertos < NUM_NAVIOS) {
        exibirTabuleiro(tabuleiro, 0);

        printf("\nInforme a linha (0 a %d) e coluna (0 a %d) para atacar (Ex: 3 5): ", TAM - 1, TAM - 1);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            printf("⚠️  Coordenadas inválidas! Tente novamente.\n");
            continue;
        }

        if (tabuleiro[linha][coluna] == 'N') {
            printf("🎯 ACERTOU UM NAVIO!\n");
            tabuleiro[linha][coluna] = 'X'; // Marca acerto
            acertos++;
        } else if (tabuleiro[linha][coluna] == '~') {
            printf("💦 Água... Errou!\n");
            tabuleiro[linha][coluna] = '*'; // Marca erro
        } else if (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == '*') {
            printf("⚠️  Você já tentou essa posição antes. Escolha outra.\n");
        }
    }

    printf("\n✅ PARABÉNS! Você destruiu todos os navios!\n");
    exibirTabuleiro(tabuleiro, 1); // Mostra o tabuleiro com os navios revelados
    printf("🎉 FIM DE JOGO 🎉\n");

    return 0;
}
