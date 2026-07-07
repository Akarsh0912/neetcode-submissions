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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;

            if(fast-> next != NULL){
                fast = fast -> next;
            }
        }

        ListNode* secHalf = slow -> next;
        slow -> next = NULL;

        ListNode* prev = NULL;
        while(secHalf != NULL){
            ListNode* temp = secHalf -> next;
            secHalf -> next = prev;
            prev = secHalf;
            secHalf  = temp;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while(second != NULL){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }



    }
};
