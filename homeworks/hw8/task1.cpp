#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

struct MyPair {
    int index;
    int startTime;
    int executionTime;

    MyPair(int index = 0, int startTime = 0, int executionTime = 0) {
        this->index = index;
        this->startTime = startTime;
        this->executionTime = executionTime;
    }
};

struct PairsByExecutionTimeComparator {
    bool operator()(const MyPair &first, const MyPair &second) const {
        if (first.executionTime == second.executionTime) {
            return second.index < first.index;
        }
        return second.executionTime < first.executionTime;
    }
};

struct PairsByStartTimeComparator {
    bool operator()(const MyPair &first, const MyPair &second) const {
        if (first.startTime == second.startTime) {
            return second.index < first.index;
        }
        return second.startTime < first.startTime;
    }
};

int main() {
    int ordersCount;
    cin >> ordersCount;

    priority_queue<MyPair, vector<MyPair>, PairsByExecutionTimeComparator> queueByExTime;
    priority_queue<MyPair, vector<MyPair>, PairsByStartTimeComparator> queueByStTime;

    int startTime, executionTime;
    for (int i = 0; i < ordersCount; ++i) {
        cin >> startTime >> executionTime;
        queueByStTime.push(MyPair(i, startTime, executionTime));
    }

    int stopTime = queueByStTime.top().startTime;

    bool isInPreparation = false;

    for (int i = 0; !queueByStTime.empty() || !queueByExTime.empty(); ++i) {
        if (!queueByStTime.empty() && i >= queueByStTime.top().startTime) {
            queueByExTime.push(queueByStTime.top());
            queueByStTime.pop();
        }
        
        if (!isInPreparation && !queueByExTime.empty() && i >= queueByExTime.top().startTime) {
            isInPreparation = true;
            stopTime += queueByExTime.top().executionTime;
            cout << queueByExTime.top().index << ' ';
            queueByExTime.pop();
        }

        if (stopTime <= i + 1) {
            isInPreparation = false;
        }
        
        
    }

    return 0;
}