#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(0));

    const int fieldSize = 10;
    char field[fieldSize][fieldSize];

    for (int i = 0; i < fieldSize; ++i) {
        for (int j = 0; j < fieldSize; ++j) {
            field[i][j] = '.';
        }
    }

    int bambooRow = generateRandomNumber(0, fieldSize - 1);
    int bambooCol = generateRandomNumber(0, fieldSize - 1);
    field[bambooRow][bambooCol] = 'B';

    int playerRow = 0;
    int playerCol = 0;

    int moves = 0;
    int eatenBambooCount = 0;

    while (true) {
        for (int i = 0; i < fieldSize; ++i) {
            for (int j = 0; j < fieldSize; ++j) {
                if (i == playerRow && j == playerCol) {
                    cout << 'P' << ' ';
                } else {
                    cout << field[i][j] << ' ';
                }
            }
            cout << endl;
        }

        if (playerRow == bambooRow && playerCol == bambooCol) {
            ++eatenBambooCount;
            cout << "you found bamboo! congratulations!!!!" << " bamboo counter: " << eatenBambooCount << endl;

            bambooRow = generateRandomNumber(0, fieldSize - 1);
            bambooCol = generateRandomNumber(0, fieldSize - 1);
            field[bambooRow][bambooCol] = 'B';
        }

        char move;
        cout << "input move (w - up, s - down, a - left, d - right): ";
        cin >> move;

        switch (move) {
            case 'w':
                if (playerRow > 0) {
                    field[playerRow][playerCol] = '.';
                    --playerRow;
                }
                break;
            case 's':
                if (playerRow < fieldSize - 1) {
                    field[playerRow][playerCol] = '.';
                    ++playerRow;
                }
                break;
            case 'a':
                if (playerCol > 0) {
                    field[playerRow][playerCol] = '.';
                    --playerCol;
                }
                break;
            case 'd':
                if (playerCol < fieldSize - 1) {
                    field[playerRow][playerCol] = '.';
                    ++playerCol;
                }
                break;
            default:
                cout << "wrong move! try again." << endl;
                continue;
        }

        ++moves;
    }

    return 0;
}
