#include <stdio.h>
#include "jogo.h"
#include "arquivo.h"

int main() {
    int opcao;
    int tabuleiroJogador[TAMANHO][TAMANHO];
    int tabuleiroInimigo[TAMANHO][TAMANHO];

    do {
        printf("\n==== BATALHA NAVAL ====\n");
        printf("1 - Novo Jogo\n");
        printf("2 - Carregar Jogo\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inicializarTabuleiros(tabuleiroJogador, tabuleiroInimigo);
                posicionarNavios(tabuleiroInimigo);
                jogar(tabuleiroJogador, tabuleiroInimigo);
                salvarJogo(tabuleiroJogador, tabuleiroInimigo);
                break;
            case 2:
                carregarJogo(tabuleiroJogador, tabuleiroInimigo);
                jogar(tabuleiroJogador, tabuleiroInimigo);
                salvarJogo(tabuleiroJogador, tabuleiroInimigo);
                break;
            case 3:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}

