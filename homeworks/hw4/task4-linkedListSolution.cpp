#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;

    Node(int value, Node *next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

class LinkedList {
    Node *head;
    Node *tail;
    int size;
    int maxSize;

public:
    LinkedList(int maxSize) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        this->maxSize = maxSize;
    }

    void pushFront(int value) {
        if (head == nullptr) {
            head = new Node(value);
            tail = head;
            ++size;
            return;
        }

        head = new Node(value, head);
        ++size;
    }

    void pushBack(int value) {
        if (tail == nullptr) {
            head = new Node(value);
            tail = head;
            ++size;
            return;
        }

        tail->next = new Node(value);
        tail = tail->next;
        ++size;
    }

    void popFront() {
        if (head == nullptr) {
            return;
        }

        Node* tmp = head;
        head = head->next;
        delete tmp;
        --size;
    }

    bool findAndMove(int element) {
        if (head == nullptr) {
            pushFront(element);
            return false;
        }

        if (head->value == element) {
            popFront();
            pushBack(element);
            return true;
        }

        Node *previous = head;
        while (previous->next != nullptr) {
            Node *current = previous->next;
            if (current->value == element) {
                previous->next = current->next;
                --size;
                pushBack(element);
                delete current;
                return true;
            }

            previous = previous->next;
        }

        if (size == maxSize) {
            popFront();
        }
        pushBack(element);
        return false;
    }

    int getSize() {
        return size;
    }

    void clear() {
        Node* current = head;
        while (current == nullptr) {
            Node* tmp = current;
            current = current->next;
            delete[] tmp;
        }

        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        clear();
    }
};

int main() {
    int maxSize;
    int count;

    cin >> count >> maxSize;

    LinkedList list(maxSize);

    int value = 0;
    for (int i = 0; i < count; ++i) {
        cin >> value;
        cout << (list.findAndMove(value) ? "true" : "false") << '\n';
    }
    return 0;
}