// Complete the findMergeNode function below.

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

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int size1 = 0;
    int size2 = 0;
    
    SinglyLinkedListNode* iter1 = head1;
    while (iter1 != nullptr) {
        iter1 = iter1->next;
        ++size1;
    }
    
    SinglyLinkedListNode* iter2 = head2;
    while (iter2 != nullptr) {
        iter2 = iter2->next;
        ++size2;
    }
    
    int diff = (size1 > size2 ? size1 - size2 : size2 - size1);
    SinglyLinkedListNode* bigger = (size1 > size2 ? head1 : head2);
    SinglyLinkedListNode* smaller = (size1 > size2 ? head2 : head1);
    
    for (int i = 0; i < diff; ++i) {
        bigger = bigger->next;
    }
    
    while (bigger != smaller) {
        bigger = bigger->next;
        smaller = smaller->next;
    }
    
    return bigger->data;
}