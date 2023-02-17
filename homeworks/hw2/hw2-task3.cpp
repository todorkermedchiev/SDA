#include <iostream>
#include <string>
#define SYMBOLS_COUNT ('z' - 'a') * 2 + 12

using namespace std;

int main() {
    string str;
    cin >> str;

    size_t symbolsCounter[SYMBOLS_COUNT]{};

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            ++symbolsCounter[str[i] - '0'];
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            ++symbolsCounter[str[i] - 'a' + 10];
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            ++symbolsCounter[str[i] - 'A' + 36];
        }
    }

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (symbolsCounter[str[i] - '0'] == 1) {
                cout << i << ' ';
            }
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            if (symbolsCounter[str[i] - 'a' + 10] == 1) {
                cout << i << ' ';
            }
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            if (symbolsCounter[str[i] - 'A' + 36] == 1) {
                cout << i << ' ';
            }
        }
    }

    return 0;
}