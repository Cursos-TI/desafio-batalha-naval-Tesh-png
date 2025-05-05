#include <stdio.h>

#define TAM 10   // Tamanho do tabuleiro (10x10)
#define NAVIO 3  // Tamanho dos navios

int main() {
    int tabuleiro[TAM][TAM];  // Matriz do tabuleiro
    int navioH[NAVIO] = {3, 3, 3}; // Navio horizontal (valores são 3)
    int navioV[NAVIO] = {3, 3, 3}; // Navio vertical

    // 1. Inicializar o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definir posições iniciais
    int linhaH = 2, colunaH = 1; // Navio horizontal começa na linha 2, coluna 1
    int linhaV = 5, colunaV = 7; // Navio vertical começa na linha 5, coluna 7

    // 3. Validar se os navios cabem e não se sobrepõem (simplificado)

    // Verifica se o navio horizontal cabe
    if (colunaH + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioH[i];
        }
    }

    // Verifica se o navio vertical cabe
    if (linhaV + NAVIO <= TAM) {
        int podeColocar = 1;

        // Verifica se já tem navio no caminho
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podeColocar = 0; // Já tem algo no caminho
                break;
            }
        }

        if (podeColocar) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioV[i];
            }
        }
    }

    // 4. Exibir o tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
