#include <bits/stdc++.h>
#include <iostream>
#include <queue>

struct Comparator {
    bool operator()(int first, int second) const {
        return second < first;
    }
};


using namespace std;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(1);
    
    int peopleCount;
    cin >> peopleCount;

    priority_queue<int> smaller;
    priority_queue<int, vector<int>, Comparator> bigger;

    double median = 0.0;

    int current;
    for (int i = 0; i < peopleCount; ++i) {
        cin >> current;

        if (current > median) {
            bigger.push(current);

            if (bigger.size() > smaller.size() + 1) {
                smaller.push(bigger.top());
                bigger.pop();
            }
        }
        else {
            smaller.push(current);

            if (smaller.size() > bigger.size() + 1) {
                bigger.push(smaller.top());
                smaller.pop();
            }
        }

        if (bigger.size() > smaller.size()) {
            median = bigger.top();
        }
        else if (smaller.size() > bigger.size()) {
            median = smaller.top();
        }
        else {
            median = (smaller.top() + bigger.top()) / 2.0;
        }
        cout << median << endl;
    }
}