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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev=curr;
            curr = tmp;
        }
        return prev;
    }

    void mergeTwoLists(ListNode* list1, ListNode* list2) {
         while(list1 && list2) {
            ListNode* t1 = list1->next;
            ListNode* t2 = list2->next;

            list1->next = list2;
            list2->next = t1;

            list1 = t1;
            list2 = t2;
        }
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
       ListNode* head2 = slow->next;
       slow->next = nullptr;
       head2 = reverse(head2);
        mergeTwoLists(head, head2);
    }
};
