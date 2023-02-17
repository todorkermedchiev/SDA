/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    if (llist == nullptr) {
        return newNode;
    }
    
    SinglyLinkedListNode* current = llist;
    for (int i = 0; i < position - 1; ++i) {
        if (current->next == nullptr) {
            // invalid position
            return nullptr;
        }
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return llist;
}