#include <iostream>
using namespace std;

int main() {
    size_t days;
    cin >> days;

    size_t* price = new size_t[days];

    for (size_t i = 0; i < days; ++i) {
        cin >> price[i];
    }

    int profit = 0;
    bool isBought = false;

    for (size_t i = 0; i < days; ++i) {
        if (i == 0) {
            if (!isBought && price[i] < price[i + 1]) {
                profit -= price[i];
                isBought = true;
            }
            continue;
        }
        else if (i == days - 1) {
            if (isBought && price[i - 1] < price[i]) {
                profit += price[i];
                isBought = false;
            }
            continue;
        }

        if (!isBought && price[i - 1] >= price[i] && price[i] <= price[i + 1]) {
            profit -= price[i];
            isBought = true;
        }
        else if (isBought && price[i - 1] <= price[i] && price[i] >= price[i + 1]) {
            profit += price[i];
            isBought = false;
        }
        
    }

    cout << profit;

    return 0;
}