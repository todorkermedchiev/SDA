#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Comparator {
    bool operator()(int first, int second) const {
        return second < first;
    }
};

int main() {
    priority_queue<int, vector<int>, Comparator> q;

    int groupSize, timeInterval, groupsCount;
    cin >> groupSize >> timeInterval >> groupsCount;

    int queriesCount;
    cin >> queriesCount;

    int queryIndex = 0;
    int current;
    for (int i = 0; i < groupsCount; ++i) {
        for (int j = 0; j < timeInterval && queryIndex < queriesCount; ++j, ++queryIndex) {
            cin >> current;
            q.push(current);
        }

        for (int j = 0; j < groupSize; ++j) {
            cout << q.top() << ' ';
            q.pop();
        }
    }

    return 0;
}