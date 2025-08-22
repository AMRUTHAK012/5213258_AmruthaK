#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** bomberMan(int r, int c, int n, char** grid) {
    if (n <= 1) {
        char** result = (char**)malloc(r * sizeof(char*));
        for (int i = 0; i < r; i++) {
            result[i] = (char*)malloc((c + 1) * sizeof(char));
            strcpy(result[i], grid[i]);
        }
        return result;
    }
    if (n % 2 == 0) {
        char** result = (char**)malloc(r * sizeof(char*));
        for (int i = 0; i < r; i++) {
            result[i] = (char*)malloc((c + 1) * sizeof(char));
            memset(result[i], 'O', c);
            result[i][c] = '\0';
        }
        return result;
    }
    int effective_n = (n % 4 == 1) ? 1 : 3;

    char** current_grid = (char**)malloc(r * sizeof(char*));
    char** next_grid = (char**)malloc(r * sizeof(char*));

    for (int i = 0; i < r; i++) {
        current_grid[i] = (char*)malloc((c + 1) * sizeof(char));
        next_grid[i] = (char*)malloc((c + 1) * sizeof(char));
        strcpy(current_grid[i], grid[i]);
    }
    for (int i = 0; i < r; i++) {
        memset(next_grid[i], 'O', c);
        next_grid[i][c] = '\0';
    }
    char** cleared_cells = (char**)malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        cleared_cells[i] = (char*)malloc((c + 1) * sizeof(char));
        memset(cleared_cells[i], '.', c);
        cleared_cells[i][c] = '\0';
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (current_grid[i][j] == 'O') {
                cleared_cells[i][j] = 'X';
                if (i > 0) cleared_cells[i - 1][j] = 'X';
                if (i < r - 1) cleared_cells[i + 1][j] = 'X';
                if (j > 0) cleared_cells[i][j - 1] = 'X';
                if (j < c - 1) cleared_cells[i][j + 1] = 'X';
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (cleared_cells[i][j] == 'X') {
                next_grid[i][j] = '.';
            }
        }
    }
    if (effective_n == 3) {
        for (int i = 0; i < r; i++) {
            free(current_grid[i]);
            free(cleared_cells[i]);
        }
        free(current_grid);
        free(cleared_cells);
        return next_grid;
    }
    for (int i = 0; i < r; i++) {
        strcpy(current_grid[i], next_grid[i]);
        memset(cleared_cells[i], '.', c);
    }
    for (int i = 0; i < r; i++) {
        memset(next_grid[i], 'O', c);
        next_grid[i][c] = '\0';
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (current_grid[i][j] == 'O') {
                cleared_cells[i][j] = 'X';
                if (i > 0) cleared_cells[i - 1][j] = 'X';
                if (i < r - 1) cleared_cells[i + 1][j] = 'X';
                if (j > 0) cleared_cells[i][j - 1] = 'X';
                if (j < c - 1) cleared_cells[i][j + 1] = 'X';
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (cleared_cells[i][j] == 'X') {
                next_grid[i][j] = '.';
            }
        }
    }
    for (int i = 0; i < r; i++) {
        free(current_grid[i]);
        free(cleared_cells[i]);
    }
    free(current_grid);
    free(cleared_cells);

    return next_grid;
}
int main() {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);

    char** grid = (char**)malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        grid[i] = (char*)malloc((c + 1) * sizeof(char));
        scanf("%s", grid[i]);
    }
    char** result = bomberMan(r, c, n, grid);

    for (int i = 0; i < r; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
        free(grid[i]);
    }
    free(result);
    free(grid);

    return 0;
}
