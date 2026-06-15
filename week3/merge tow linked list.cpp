/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void merge(ListNode*& list1, ListNode*& list2, ListNode*& head) {
        if(head == NULL) {
            if(list1->val <= list2->val) {
                head = list1;
                list1 = list1->next;
            }
            else {
                head = list2;
                list2 = list2->next;
            }
            head->next = nullptr;
            return;
        }
        ListNode* tail = head;
        while(tail->next)
            tail = tail->next;
        if(list1->val <= list2->val) {
            ListNode* tmp = list1;
            list1 = list1->next;
            tmp->next = nullptr;
            tail->next = tmp;
        }
        else {
            ListNode* tmp = list2;
            list2 = list2->next;
            tmp->next = nullptr;
            tail->next = tmp;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* head = NULL;

        while(list1 && list2) {
            merge(list1, list2, head);
        }

        ListNode* tail = head;
        while(tail->next)
            tail = tail->next;

        if(list1)
            tail->next = list1;
        else
            tail->next = list2;

        return head;
    }
};
