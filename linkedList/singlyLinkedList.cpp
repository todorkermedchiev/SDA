#include "singlyLinkedList.hpp"
using namespace std;

int main() {
    SinglyLinkedList list;
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);

    // list.insert_at(50, 6);
    // list.remove_at(6);

    list.reverse();

    cout << list;

    return 0;
}