#pragma once
#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(const int& value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    // the rule of four
    ~SinglyLinkedList() {
        clear();
    }

    void push_front(const int& value);
    void push_back(const int& value);
    void pop_front();
    void pop_back();
    void insert_at(const int& value, int position);
    void remove_at(int position);
    const int& get_at(int position);
    void set_at(const int& value, int position);

    void reverse();
    void clear();

    friend std::ostream& operator<<(std::ostream& out, const SinglyLinkedList& list);
};

void SinglyLinkedList::push_front(const int& value) {
    if (head == nullptr) {
        // the list is empty
        head = new Node(value);
        tail = head;
        ++size;
        return;
    }

    head = new Node(value, head);
    ++size;
}

void SinglyLinkedList::push_back(const int& value) {
    if (tail == nullptr) {
        // the list is empty
        head = new Node(value);
        tail = head;
        ++size;
        return;
    }

    tail->next = new Node(value);
    tail = tail->next;
    ++size;
}

void SinglyLinkedList::pop_front() {
    if (head == nullptr) {
        return;
    }

    Node* tmp = head;
    head = head->next;
    delete tmp;
    --size;
}

void SinglyLinkedList::pop_back() {
    if (tail == nullptr) {
        return;
    }

    // finding the value before the last
    Node* previous = head;
    while (previous->next != tail) { // while (previous->next->next != nullptr) { 
        previous = previous->next;
    }

    delete previous->next;
    previous->next = nullptr;
    // delete tail;
    tail = previous;
    --size;
}

void SinglyLinkedList::insert_at(const int& value, int position) {
    // invalid position
    if (position < 0 || position > size) {
        return;
    }

    if (position == 0) {
        push_front(value);
        return;
    }
    if (position == size) {
        push_back(value);
        return;
    }

    Node* previous = head;
    for (int i = 0; i < position - 1; ++i) {
        previous = previous->next;
    }

    // Node* newNode = new Node(value);
    // newNode->next = previous->next;
    // previous->next = newNode;

    previous->next = new Node(value, previous->next);
    ++size;
}

void SinglyLinkedList::remove_at(int position) {
    // invalid position
    if (head == nullptr || position < 0 || position >= size) {
        return;
    }

    if (position == 0) {
        pop_front();
        return;
    }
    if (position == size - 1) {
        pop_back();
        return;
    }

    Node* previous = head;
    for (int i = 0; i < position - 1; ++i) {
        previous = previous->next;
    }

    Node* current = previous->next;
    previous->next = current->next;
    delete current;
    --size;
}

const int& SinglyLinkedList::get_at(int position) {
    if (head == nullptr || position < 0 || position >= size) {
        // throw invalid_argument("Index out of range exception.");
    }

    Node* current = head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }

    return current->value;
}

void SinglyLinkedList::set_at(const int& value, int position) {
    if (head == nullptr || position < 0 || position >= size) {
        return;
        // throw invalid_argument("Index out of range exception.");
    }

    Node* current = head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }

    current->value = value;
}

void SinglyLinkedList::reverse() {
    if (head == nullptr) {
        return;
    }

    Node *previous = nullptr;
    Node *current = head;
    Node *next = current->next;

    while (current != nullptr) {
        current->next = previous;

        previous = current;
        current = next;
        if (current != nullptr) {
            next = current->next;
        }
    }

    tail = head;
    head = previous;
}

void SinglyLinkedList::clear() {
    Node* current = head;
    while (current == nullptr) {
        Node* tmp = current;
        current = current->next;
        delete[] tmp;
    }

    head = nullptr;
    tail = nullptr;
}

std::ostream& operator<<(std::ostream& out, const SinglyLinkedList& list) {
    Node* current = list.head;
    while (current != nullptr) {
        out << current->value << ' ';
        current = current->next;
    }
    out << std::endl;
    return out;
}