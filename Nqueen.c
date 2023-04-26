#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 10

int queen_count = 0;

void print_board(int board[], int n) {
    printf("\nSolution %d:\n", queen_count);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                printf(" Q ");
            } else {
                printf(" - ");
            }
        }
        printf("\n");
    }
}

bool is_safe(int board[], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void queen(int board[], int row, int n) {
    if (row == n) {
        queen_count++;
        print_board(board, n);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col, n)) {
            board[row] = col;
            queen(board, row + 1, n);
            board[row] = -1;
        }
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int board[MAX_N];
    for (int i = 0; i < n; i++) {
        board[i] = -1;
    }

    queen(board, 0, n);
    printf("\nTotal number of calls to queen procedure: %d\n", queen_count);

    return 0;
}
