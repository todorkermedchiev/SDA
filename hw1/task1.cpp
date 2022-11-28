#include <iostream>
using namespace std;

int main() {
    int quantity;
    cin >> quantity;

    char** lists = new char*[quantity];

    for (int i = 0; i < quantity; ++i) {
        int len;
        cin >> len;
        lists[i] = new char[len + 1];
        cin >> lists[i];
        lists[i][len] = '\0';
    }

    for (int i = 0; i < quantity; ++i) {
        int counter = 0;
        for (int j = 0; lists[i][j] != '\0'; ++j) {
            if (lists[i][j] == lists[i][j + 1]) {
                ++counter;
            }
        }
        cout << counter << endl;
        delete[] lists[i];
    }

    delete[] lists;  
    return 0;
}
