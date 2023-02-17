#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

const int INVALID = -5000000;

using namespace std;

int search(int row, int column, int **matrix, int **dp, bool **diagonalCells, int size) {
    if (row == size - 1 && column == size - 1) {
        return matrix[row][column];
    }

    if (row >= size || column >= size) {
        return 0;
    }
    
    if (column < size - 1 && dp[row][column + 1] == INVALID) {
        dp[row][column + 1] = search(row, column + 1, matrix, dp, diagonalCells, size);
    }
    if (row < size - 1 && dp[row + 1][column] == INVALID) {
        dp[row + 1][column] = search(row + 1, column, matrix, dp, diagonalCells, size);
    }
    if (row < size - 1 && column < size - 1 
        && diagonalCells[row + 1][column + 1] && dp[row + 1][column + 1] == INVALID) {
        dp[row + 1][column + 1] = search(row + 1, column + 1, matrix, dp, diagonalCells, size);
    }
    
    int right = (column < size - 1 ? dp[row][column + 1] : INVALID);
    int down = (row < size - 1 ? dp[row + 1][column] : INVALID);
    int rightDown = (row < size - 1 && column < size - 1 && diagonalCells[row + 1][column + 1] ?
                     dp[row + 1][column + 1] : INVALID);
    
    return dp[row][column] = max(max(right, down), rightDown) + matrix[row][column];
}

int main() {
    int size;
    cin >> size;
    
    bool **diagonalCells = new bool*[size];
    int **matrix = new int*[size];
    int **dp = new int*[size];
    for (int i = 0; i < size; ++i) {
        diagonalCells[i] = new bool[size];
        matrix[i] = new int[size];
        dp[i] = new int[size];
        
        for (int j = 0; j < size; ++j) {
            cin >> matrix[i][j];
            diagonalCells[i][j] = false;
            dp[i][j] = INVALID;
        }
    }
    
    int diagonalCellsCount;
    cin >> diagonalCellsCount;
    
    for (int i = 0; i < diagonalCellsCount; ++i) {
        int row, col;
        cin >> row >> col;
        
        diagonalCells[row][col] = true;
    }
    
    cout << search(0, 0, matrix, dp, diagonalCells, size);
    
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
        delete[] dp[i];
        delete[] diagonalCells[i];
    }
    delete[] matrix;
    delete[] dp;
    delete[] diagonalCells;
    
    return 0;
}
