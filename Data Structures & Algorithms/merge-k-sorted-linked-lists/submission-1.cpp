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
    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > pg;

        for(auto head : lists){
            if(head != NULL){
                pg.push(head);
            }
        }    

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!pg.empty()){
            ListNode* node = pg.top();

            pg.pop();

            tail->next = node;
            tail = tail->next;

            if(node->next != NULL){
                pg.push(node->next);
            }
        }
        return dummy->next;
    }
};
