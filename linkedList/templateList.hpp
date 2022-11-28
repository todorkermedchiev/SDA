#pragma once
#include <iostream>

template <typename T>
struct Node {
    T value;
    Node* next;

    Node(const T& value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

template <typename T>
class SinglyLinkedList;

template <typename T>
std::ostream &operator<<(std::ostream &out, const SinglyLinkedList<T> &vec);

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
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

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    void insert_at(const T& value, int position);
    void remove_at(int position);
    const T& get_at(int position);
    void set_at(const T& value, int position);

    void clear();

    friend std::ostream& operator<< <> (std::ostream& out, const SinglyLinkedList& list);
};

template <typename T>
void SinglyLinkedList<T>::push_front(const T& value) {
    if (head == nullptr) {
        // the list is empty
        head = new Node(value);
        tail = head;
        return;
    }

    head = new Node(value, head);
    ++size;
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& value) {
    if (tail == nullptr) {
        // the list is empty
        head = new Node(value);
        tail = head;
        return;
    }

    tail->next = new Node(value);
    tail = tail->next;
    ++size;
}

template <typename T>
void SinglyLinkedList<T>::pop_front() {
    if (head == nullptr) {
        return;
    }

    Node<T>* tmp = head;
    head = head->next;
    delete[] tmp;
    --size;
}

template <typename T>
void SinglyLinkedList<T>::pop_back() {
    if (tail = nullptr) {
        return;
    }

    // finding the value before the last
    Node<T>* previous = head;
    while (previous->next != nullptr) {
        previous = previous->next;
    }

    previous->next = nullptr;
    delete tail;
    tail = previous;
    --size;
}

template <typename T>
void SinglyLinkedList<T>::insert_at(const T& value, int position) {
    // invalid position
    if (position < 0 || position > size) {
        return;
    }

    if (position = 0) {
        push_front(value);
        return;
    }
    if (position = size) {
        push_back(value);
        return;
    }

    Node<T>* previous = head;
    for (int i = 0; i < position; ++i) {
        previous = previous->next;
    }

    // Node* newNode = new Node(value);
    // newNode->next = previous->next;
    // previous->next = newNode;

    previous->next = new Node(value, previous->next);
    ++size;
}

template <typename T>
void SinglyLinkedList<T>::remove_at(int position) {
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

    Node<T>* previous = head;
    for (int i = 0; i < position; ++i) {
        previous = previous->next;
    }

    Node<T>* current = previous->next;
    previous->next = current->next;
    delete current;
    --size;
}

template <typename T>
const T& SinglyLinkedList<T>::get_at(int position) {
    if (head == nullptr || position < 0 || position >= size) {
        // throw invalid_argument("Index out of range exception.");
    }

    Node<T>* current = head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }

    return current->value;
}

template <typename T>
void SinglyLinkedList<T>::set_at(const T& value, int position) {
    if (head == nullptr || position < 0 || position >= size) {
        return;
        // throw invalid_argument("Index out of range exception.");
    }

    Node<T>* current = head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }

    current->value = value;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
    Node<T>* current = head;
    while (current == nullptr) {
        Node<T>* tmp = current;
        current = current->next;
        delete[] tmp;
    }

    head = nullptr;
    tail = nullptr;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const SinglyLinkedList<T>& list) {
    Node<T>* current = list.head;
    while (current != list.head) {
        out << current->value << ' ';
    }
    out << std::endl;
    return out;
}