#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* newHead = reverseList(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
};

/*
    За проверка на цикъл в списък:
    2 итератора:
    единия се мести по всеки елемент, другия се мести през 1
    ако се срещнат, значи има цикъл;

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* iter1 = head;
        ListNode* iter2 = head;
        
        while (iter2 != nullptr && iter2->next != nullptr) {
            iter1 = iter1->next;
            iter2 = iter2->next->next;
            
            if (iter1 == iter2) {
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution3 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int len1 = 0;
        int len2 = 0;
        
        ListNode* iter1 = headA;
        ListNode* iter2 = headB;
        
        while (iter1 != nullptr) {
            len1++;
            iter1 = iter1->next;
        }
        
        while (iter2 != nullptr) {
            len2++;
            iter2 = iter2->next;
        }
        
        int biggerSize;
        int smallerSize;
        ListNode* bigger;
        ListNode* smaller;
        
        if (len1 > len2) {
            bigger = headA;
            smaller = headB;
            biggerSize = len1;
            smallerSize = len2;
        }
        else {
            bigger = headB;
            smaller = headA;
            biggerSize = len2;
            smallerSize = len1;
        }
        
        for (int i = 0; i < biggerSize - smallerSize; ++i) {
            bigger = bigger->next;
        }
        
        while (bigger != smaller) {
            bigger = bigger->next;
            smaller = smaller->next;
            
            if (bigger == smaller) {
                return bigger;
            }
        }
        
        return nullptr;
    }
};

