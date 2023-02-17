#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int peopleCount;
    cin >> peopleCount;

    int *people = new int[peopleCount];
    for (int i = 0; i < peopleCount; ++i) {
        cin >> people[i];
    }

    queue<int> q;
    stack<int> s;

    int i = 0;
    while (i < peopleCount) {
        while (i < peopleCount && people[i] > 0) {
            s.push(people[i++]);
        }
        while (i < peopleCount && people[i] < 0) {
            q.push(people[i++]);
        }

        while (!s.empty() && !q.empty()) {
            if (s.top() > abs(q.front())) {
                q.pop();
            }
            else if (s.top() < abs(q.front())) {
                s.pop();
            }
            else {
                q.pop();
                s.pop();
            }
        }

        while (!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }
    }

    stack<int> last;
    while (!s.empty()) {
        last.push(s.top());
        s.pop();
    }
    while (!last.empty()) {
        cout << last.top() << ' ';
        last.pop();
    }

    return 0;
}