#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Comparator {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    
    priority_queue<int, vector<int>, Comparator> q;
    
    int input;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        q.push(input);
    }
    
    int counter = 0;
    while (q.top() < M) {
        if (q.empty()) {
            cout << -1;
            return 0;
        }
        
        int first = q.top();
        q.pop();
        
        if (q.empty()) {
            cout << -1;
            return 0;
        }
        
        int second = q.top();
        q.pop();
        q.push(first + 2 * second);
        ++counter;
    }
    
    cout << counter;
    
    return 0;
}