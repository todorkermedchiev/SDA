#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int boardSize, shipsCount, shipSize;
    cin >> boardSize >> shipsCount >> shipSize;

    set<int> shots;

    int shotsCount;
    cin >> shotsCount;

    // Намиране на максималния брой кораби, които могат да се разположат в полето
    int allPossibleShipsCount = boardSize / shipSize;
    // Проверка дали тези кораби и клетките между всеки два от тях (минимум една)
    // могат да се съберат в полето. Намаляме бройката с 1 докато не се съберат в полето
    while (allPossibleShipsCount > 0 &&
            allPossibleShipsCount * shipSize + allPossibleShipsCount - 1 > boardSize) {
        --allPossibleShipsCount;
    }

    int availableCells;
    int possibleShipsCount;
    for (int i = 0; i < shotsCount; ++i) {
        int currentShot;
        cin >> currentShot;
        auto it = shots.insert(currentShot);

        int left = (*shots.begin() != currentShot ? *prev(it.first) : 0);
        int right = (next(it.first) != shots.end() ? *next(it.first) : boardSize + 1);

        // Намиране на възможния брой кораби в целия интервал от left до right
        int currentPossibleShipsCount = (right - left - 1) / shipSize;
        // Добавям към клeтките, които заемат тези кораби още currentPossibleShipsCount - 1
        // (това са клетките между корабите) и проверявам дали се събират в свободните клетки
        while (currentPossibleShipsCount > 0 &&
               currentPossibleShipsCount * shipSize + currentPossibleShipsCount - 1 > right - left - 1) {
            --currentPossibleShipsCount;
        }

        // Изваждане от общия брой кораби, които досега е било възможно да се разположат на полето, 
        // броя на корабите, които е възможно да се разположат в интервала от left до right
        allPossibleShipsCount -= currentPossibleShipsCount;

        // Намиране на възможния брой кораби в целия интервал наляво от текущия изстрел, т.е в интервала
        // от left до currentShot
        availableCells = currentShot - left - 1;
        possibleShipsCount = availableCells / shipSize;

        while (possibleShipsCount > 0 &&
               possibleShipsCount * shipSize + possibleShipsCount - 1 > availableCells) {
            --possibleShipsCount;
        }
        allPossibleShipsCount += possibleShipsCount;

        // Намиране на възможния брой кораби в целия интервал надясно от текущия изстрел, т.е в интервала
        // от currentShot до right
        availableCells = right - currentShot - 1;
        possibleShipsCount = availableCells / shipSize;

        while (possibleShipsCount > 0 &&
               possibleShipsCount * shipSize + possibleShipsCount - 1 > availableCells) {
            --possibleShipsCount;
        }
        allPossibleShipsCount += possibleShipsCount;

        // Проверка дали първоначалния брой кораби все още може да се побере в полето
        if (allPossibleShipsCount < shipsCount) {
            cout << i + 1;
            return 0;
        }
    }
    
    cout << -1;
    return 0;
}

/*
15 2 3
5
3 5 7 9 13
*/