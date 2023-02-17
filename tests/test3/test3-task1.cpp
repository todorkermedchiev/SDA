#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    
    Node(int value, Node *left = nullptr, Node *right = nullptr) {
        this->value = value;
        this->left = left;
        this->right = right;
    }        
};

struct Tree {
    Node *root;
    
    Tree() {
        root = nullptr;
    }
    
    void insert(int newVal) {
        if (root == nullptr) {
            root = new Node(newVal);
            return;
        }
        insert(root, newVal);
    }
    
    Node *insert(Node *current, int newVal) {
        if (current == nullptr) {
            return new Node(newVal);
        }
        if (newVal < current->value) {
            current->left = insert(current->left, newVal);
        }
        else if (newVal > current->value) {
            current->right = insert(current->right, newVal);
        }
        return current;        
    }
    
    void print() {
        print(root);
    }
    
    void print(Node *current) {
        if (current == nullptr) {
            return;
        }
        
        if (current->left != nullptr && current->right != nullptr) {
            cout << current->value << ' ';
        }
        print(current->left);
        print(current->right);
    }
    
};

int main() {
    int treesCount;
    cin >> treesCount;
    
    int nodesCount;
    int input;
    for (int i = 0; i < treesCount; ++i) {
        Tree tree;
        cin >> nodesCount;
        
        for (int j = 0; j < nodesCount; ++j) {
            cin >> input;
            tree.insert(input);
        }
        
        tree.print();
        cout << '\n';
    }
    return 0;
}
