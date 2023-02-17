#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct Ball {
    int number;
    int color;
    static int counter;

    Ball(int color) {
        this->number = counter++;
        this->color = color;
    }
};
int Ball::counter = 0;

int insertOrErase(list<Ball> &balls, list<Ball>::iterator current) {
    list<Ball>::iterator right = current;
    list<Ball>::iterator left = prev(current);
    
    int counter = 0;
    
    while (right != balls.end() && right->color == current->color) {
        ++counter;
        ++right;
    }
    while (left->color == current->color) {
        ++counter;
        --left;
    }

    if (counter >= 3) {
        ++left;

        balls.erase(left, right);
        if (balls.empty()) {
            return counter;
        }
        if (right != balls.end() && right != balls.begin() && prev(right)->color == right->color) {
            counter += insertOrErase(balls, right);
        }
        
        return counter;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_COUNT = 100000;
    int ballsCount;
    int queriesCount;

    list<Ball> balls;
    list<Ball>::iterator iterators[2 * MAX_COUNT + 1];

    cin >> ballsCount;
    for (int i = 0; i < ballsCount; ++i) {
        int color;

        cin >> color;
        balls.insert(balls.end(), Ball(color));
        iterators[i] = prev(balls.end());
    }

    cin >> queriesCount;
    int *targets = new int[queriesCount];
    int *colors = new int[queriesCount];

    for (int i = 0; i < queriesCount; ++i) {
        cin >> targets[i] >> colors[i];
    }


    for (int i = 0; i < queriesCount; ++i) {
        if (balls.empty()) {
            cout << "Game Over\n";
            continue;
        }

        balls.insert(next(iterators[targets[i]]), Ball(colors[i]));
        iterators[next(iterators[targets[i]])->number] = next(iterators[targets[i]]);

        int result = insertOrErase(balls, next(iterators[targets[i]]));
        cout << result << '\n';
    }

    if (balls.empty()) {
        cout << -1 << '\n';
    }
    else {
        list<Ball>::iterator iter = balls.begin();
        for (int i = 0; i < balls.size(); ++i) {
            cout << iter->color << ' ';
            ++iter;
        }
    }

    delete[] targets;
    delete[] colors;
    return 0;
}