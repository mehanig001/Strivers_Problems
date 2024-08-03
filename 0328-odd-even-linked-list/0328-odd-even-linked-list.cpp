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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);

        ListNode *i = odd, *j = even;
        int ctr = 1;

        ListNode* temp = head;
        while(temp){
            if(ctr & 1){
                i->next = new ListNode(temp->val);
                i = i->next;
            }
            else{
                j->next = new ListNode(temp->val);
                j = j->next;
            }
            ctr++;
            temp = temp->next;
        }

        odd = odd->next;
        even = even->next;

       
        i->next = even;
        return odd;
        
        
    }
};