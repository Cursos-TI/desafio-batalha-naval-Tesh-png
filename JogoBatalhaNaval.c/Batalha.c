#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Horizontal
    int lh = 2, ch = 1;
    for (int i = 0; i < NAVIO; i++)
        tabuleiro[lh][ch + i] = 3;

    // Vertical
    int lv = 5, cv = 7;
    for (int i = 0; i < NAVIO; i++)
        tabuleiro[lv + i][cv] = 3;
}

void construirCone(int habilidade[HABILIDADE][HABILIDADE]) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            if (j >= 2 - i && j <= 2 + i) // forma de cone invertido
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void construirCruz(int habilidade[HABILIDADE][HABILIDADE]) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            if (i == 2 || j == 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void construirOctaedro(int habilidade[HABILIDADE][HABILIDADE]) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HABILIDADE][HABILIDADE], int origemX, int origemY) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            int x = origemX + i - 2;
            int y = origemY + j - 2;

            if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[x][y] == 0)
                    tabuleiro[x][y] = 5;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(". ");
            else if (tabuleiro[i][j] == 3)
                printf("N ");
            else if (tabuleiro[i][j] == 5)
                printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[HABILIDADE][HABILIDADE], cruz[HABILIDADE][HABILIDADE], octaedro[HABILIDADE][HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 1, 4);      // Aplica cone no ponto (1,4)
    aplicarHabilidade(tabuleiro, cruz, 5, 2);      // Aplica cruz no ponto (5,2)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Aplica octaedro no ponto (7,7)

    exibirTabuleiro(tabuleiro);

    return 0;
}
