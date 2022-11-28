#include <iostream>
#include <vector>
using namespace std;

// template <typename T>
// void Swap(T& first, T& second) {
//     T tmp = first;
//     first = second;
//     second = first;
// }

// template <typename T>
// void Sort(vector<T>& vec, size_t size) {
//     for (int i = 0; i < size - 1; ++i) {
//         size_t minIndex = i + 1;
//         for (int j = i + 1; j < size; ++j) {
//             if (vec[j] < vec[minIndex]) {
//                 minIndex = j;
//             }
//         }

//         if (vec[i] > vec[minIndex]) {
//             swap<T>(vec[i], vec[minIndex]);
//         }
//     }
// }

// int main() {
//     size_t ticketsCount;
//     cin >> ticketsCount;

//     vector<int> tickets;
    
//     size_t positiveCount = 0;

//     for (size_t i = 0; i < ticketsCount; ++i) {
//         int tmp;
//         cin >> tmp;
//         if (tmp > 0) {
//             tickets.push_back(tmp);
//             ++positiveCount;
//         }
//     }

//     Sort<int>(tickets, positiveCount);

//     for (size_t i = 0; i < positiveCount - 1; ++i) {
//         if (tickets[i + 1] - tickets[i] > 1) {
//             cout << tickets[i] + 1;
//             return 0;
//         }
//     }

//     cout << tickets[positiveCount - 1] + 1;
//     return 0;
// }

int main() {
    size_t ticketsCount;
    cin >> ticketsCount;

    size_t* tickets = new size_t[ticketsCount];
    bool* isContained = new bool[ticketsCount]{};
    
    for (size_t i = 0; i < ticketsCount; ++i) {
        cin >> tickets[i];  
    }

    for (size_t i = 0; i < ticketsCount; ++i) {
        if (tickets[i] > 0 && tickets[i] <= ticketsCount) {
            isContained[tickets[i] - 1] = true;
        }
    }

    for (size_t i = 0; i < ticketsCount; ++i) {
        if (!isContained[i]) {
            cout << i + 1;
            delete[] tickets;
            delete[] isContained; 
            return 0;
        }
    }

    cout << ticketsCount + 1;

    delete[] tickets;
    delete[] isContained;  
    return 0;
}