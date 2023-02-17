#include <iostream>
#include <list>
using namespace std;

struct Ball;

struct Node {
    Ball *value;
    Node *previous;
    Node *next;

    Node(Ball *value, Node *previous = nullptr, Node *next = nullptr) {
        this->value = value;
        this->previous = previous;
        this->next = next;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail;
    }

    int getSize() {
        return size;
    }

    bool empty() {
        return head == nullptr;
    }

    void pushFront(Ball *newValue) {
        if (head == nullptr) {
            head = new Node(newValue);
            tail = head;
            ++size;
            return;
        }

        head = new Node(newValue, nullptr, head);
        ++size;
    }

    void pushBack(Ball *newValue) {
        if (head == nullptr) {
            head = new Node(newValue);
            tail = head;
            ++size;
            return;
        }

        tail->next = new Node(newValue, tail, nullptr);
        tail = tail->next;
        ++size;
    }

    void popFront() {
        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node *tmp = head;
        head = head->next;
        head->previous = nullptr;
        delete tmp;
    }

    void popBack() {
        if (tail == nullptr) {
            return;
        }
        if (head == tail) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node *tmp = tail;
        tail = tail->previous;
        tail->next = nullptr;
        delete tmp;
    }

    void remove(Node *current) {
        if (current == nullptr) {
            return;
        }
        if (current == head) {
            popFront();
            return;
        }
        if (current == tail) {
            popBack();
            return;
        }

        Node* previous = current->previous;
        Node* next = current->next;
        previous->next = next;
        next->previous = previous;
        delete current;
        --size;
    }

    void insert(Node *current, Ball *value) {
        if (current == nullptr) {
            return;
        }
        if (current == head) {
            pushFront(value);
            return;
        }
        if (current == tail) {
            pushBack(value);
            return;
        }
        Node *next = current->next;
        current->next = new Node(value, current, next);
        next->previous = current->next;
    }

    ~LinkedList() {
        Node *iter = head;
        while (iter != nullptr) {
            Node *tmp = iter;
            iter = iter->next;
            // delete tmp->value;
            delete tmp;
        }
    }
};

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

int insertOrErase(LinkedList &balls, Node *current) {
    Node *right = current;
    Node *left = current->previous;
    
    int counter = 0;
    
    while (right != nullptr && right->value->color == current->value->color) {
        ++counter;
        right = right->next;
    }
    while (left != nullptr && left->value->color == current->value->color) {
        ++counter;
        left = left->previous;
    }

    if (counter >= 3) {
        if (left == nullptr) {
            left = balls.getHead();
        }
        else {
            left = left->next;
        }
        
        while (left != right) {
            Node* tmp = left;
            left = left->next;
            balls.remove(tmp);
        }
        if (balls.empty()) {
            return counter;
        }
        // if (right == nullptr) {
        //     right = balls.getTail();
        // }

        if (right != nullptr && right->previous != nullptr
            && right->previous->value->color == right->value->color) {
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

    // Node **iterators = new Node*[ballsCount + queriesCount + 1];
    Node *iterators[2 * MAX_COUNT + 1];
    LinkedList balls;

    cin >> ballsCount;
    cin.ignore();
    for (int i = 0; i < ballsCount; ++i) {
        int color;
        cin >> color;
        cin.ignore();
        balls.pushBack(new Ball(color));
        iterators[i] = balls.getTail();
    }

    cin >> queriesCount;
    cin.ignore();
    int *targets = new int[queriesCount];
    int *colors = new int[queriesCount];

    for (int i = 0; i < queriesCount; ++i) {
        cin >> targets[i] >> colors[i];
        cin.ignore();
    }


    for (int i = 0; i < queriesCount; ++i) {
        if (balls.empty()) {
            cout << "Game Over\n";
            continue;
        }

        balls.insert(iterators[targets[i]], new Ball(colors[i]));
        iterators[iterators[targets[i]]->next->value->number] = iterators[targets[i]]->next;

        int result = insertOrErase(balls, iterators[targets[i]]->next);
        cout << result << '\n';
    }

    if (balls.empty()) {
        cout << -1 << '\n';
    }
    else {
        Node *iter = balls.getHead();
        while (iter != nullptr) {
            cout << iter->value->color << ' ';
            iter = iter->next;
        }
    }

    delete[] iterators;
    delete[] targets;
    delete[] colors;
    return 0;
}

/*
15
2 2 1 1 1 2 2 2 2 3 3 3 1 1 2
4
10 3
6 2
1 1
3 2
*/