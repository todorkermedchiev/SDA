#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int row;
    int column;

    Point(int row = 0, int column = 0) : row(row), column(column) {}
};

enum Edge {
    top,
    right,
    bottom,
    left,
    none
};

Edge checkIfOnEdge(int rows, int columns, Point current) {
    if (current.row <= 0) {
        return Edge::top;
    }
    if (current.row >= rows - 1) {
        return Edge::bottom;
    }
    if (current.column <= 0) {
        return Edge::left;
    }
    if (current.column >= columns - 1) {
        return Edge::right;
    }
    return Edge::none;
}

int main() {
    int rows, columns;
    int days;

    cin >> rows >> columns;
    cin >> days;

    int **apples = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        apples[i] = new int[columns]{-1};
    }

    int startRow = 0;
    int startColumn = 0;

    queue<Point> applesQueue;
    while (cin >> startRow >> startColumn) {
        apples[startRow - 1][startColumn - 1] = 0;
        Point tmp(startRow - 1, startColumn - 1);
        applesQueue.push(tmp);
    }

    Point current = applesQueue.front();
    int passedDaysCount = 1;
    while (!applesQueue.empty() && passedDaysCount < days) {
        if (checkIfOnEdge(rows, columns, current) != Edge::top) {
            int newRow = current.row - 1;
            int newColumn = current.column;
            if (apples[newRow][newColumn] == -1) {
                apples[newRow][newColumn] = passedDaysCount;
                applesQueue.push(Point(newRow, newColumn));
            }
        }

        if (checkIfOnEdge(rows, columns, current) != Edge::right) {
            int newRow = current.row;
            int newColumn = current.column + 1;
            if (apples[newRow][newColumn] == -1) {
                apples[newRow][newColumn] = passedDaysCount;
                applesQueue.push(Point(newRow, newColumn));
            }
        }

        if (checkIfOnEdge(rows, columns, current) != Edge::bottom) {
            int newRow = current.row + 1;
            int newColumn = current.column;
            if (apples[newRow][newColumn] == -1) {
                apples[newRow][newColumn] = passedDaysCount;
                applesQueue.push(Point(newRow, newColumn));
            }
        }

        if (checkIfOnEdge(rows, columns, current) != Edge::left) {
            int newRow = current.row;
            int newColumn = current.column - 1;
            if (apples[newRow][newColumn] == -1) {
                apples[newRow][newColumn] = passedDaysCount;
                applesQueue.push(Point(newRow, newColumn));
            }
        }

        applesQueue.pop();
        if (applesQueue.empty()) {
            break;
        }
        current = applesQueue.front();
        passedDaysCount = apples[current.row][current.column] + 1;
    }

    int counter = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (apples[rows][columns] == -1) {
                ++counter;
            }
        }
        delete[] apples[i];
    }
    delete[] apples;

    cout << counter;

    return 0;
}