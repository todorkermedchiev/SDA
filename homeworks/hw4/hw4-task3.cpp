/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int data) {
        this->data = data;
        next = nullptr;
    }
};

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if (llist == nullptr) {
        return nullptr;
    }
    if (position == 0) {
        SinglyLinkedListNode* newHead = llist->next;
        delete llist;
        return newHead;
    }
    SinglyLinkedListNode* previous = llist;
    for (int i = 0; i < position - 1; ++i) {
        previous = previous->next;
        if (previous == nullptr) {
            return nullptr;
        }
    }
    
    SinglyLinkedListNode* current = previous->next;
    previous->next = current->next;
    delete current;
    
    return llist;
}