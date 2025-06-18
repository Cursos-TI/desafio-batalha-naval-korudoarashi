#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define ROWS 10
#define COLS 10

void clearBoard(int board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            board[i][j] = 0;

}

void cross(int x, int y, int board[ROWS][COLS]) {
    clearBoard(board);

    for(int i = 0; i < ROWS; i++)
        board[i][x] = 1;

    for(int j = 0; j < COLS; j++)
        board[y][j] = 1;
}

void cone(int x, int y, int board[ROWS][COLS]) {
    clearBoard(board);

    if (y + 2 < ROWS) {
        board[y][x] = 1;
        if (x - 1 >= 0 && x + 1 < COLS) {
            board[y + 1][x - 1] = 1;
            board[y + 1][x] = 1;
            board[y + 1][x + 1] = 1;
        }
        if (x - 2 >= 0 && x + 2 < COLS) {
            for (int j = x - 2; j <= x + 2; j++) {
                board[y + 2][j] = 1;
            }
        }
    }
}

void octahedron(int x, int y, int board[ROWS][COLS]) {
    clearBoard(board);

    if (y - 1 >= 0 && y + 1 < ROWS && x - 1 >= 0 && x + 1 < COLS) {
        board[y - 1][x] = 1;
        board[y][x - 1] = 1;
        board[y][x] = 1;
        board[y][x + 1] = 1;
        board[y + 1][x] = 1;
    }
}

void showBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j] == 1 ? 3 : 0);
        }
        printf("\n");
    }
}

int main() {
    // Criando tabuleiro usando uma matriz bidimensional
    int board[ROWS][COLS] = {0};

    // Posicionando primeiro navio
    for(int i = 2; i < 5; i++) {
        board[i][1] = 1;
    }

    // Posicionando segundo navio
    for (int i = 4; i < 8; i++) {
        board[4][i] = 1;
    }

    // Posicionando terceiro navio
    for (int i = 7; i < 10; i++) {
        board[i][i] = 1;
    }

    // Posicionando quarto navio
    for (int i = 0; i < 3; i++) {
        board[7 + i][3 - i] = 1;
    }

    // Exibindo tabuleiro
    printf("\nTabuleiro:\n");
    showBoard(board);

    // Exibindo Cruz
    printf("\nCruz:\n");
    cross(2, 2, board);
    showBoard(board);

    // Exibindo Cone
    printf("\nCone:\n");
    cone(2, 2, board);
    showBoard(board);

    // Exibindo Octaedro
    printf("\nOctaedro:\n");
    octahedron(2, 2, board);
    showBoard(board);

    return 0;
}