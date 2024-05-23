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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;



        int ct = 0;
        while(ct < n && fast){
            fast = fast->next;
            ct++;
        }

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        if(slow->next && fast)
        slow->next = slow->next->next;

        else{
            if(slow == head){
                return head->next;
            }
        }
        

        return head;

    }
};