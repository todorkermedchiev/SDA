
struct Node {
    int value;
    Node *previous;
    Node *next;

    Node(int value, Node *previous = nullptr, Node *next = nullptr) {
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

    void pushFront(int newValue) {
        if (head == nullptr) {
            head = new Node(newValue);
            tail = head;
            ++size;
            return;
        }

        head = new Node(newValue, nullptr, head);
        ++size;
    }

    void pushBack(int newValue) {
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

    void remove(Node *current) {
        Node* previous = current->previous;
        Node* next = current->next;
        previous->next = next;
        next->previous = previous;
        delete current;
    }

};
