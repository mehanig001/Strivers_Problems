/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        
        if(head->next == head)return head;

        ListNode *slow = head;
        ListNode *fast = head;

    
        do{
            slow = slow->next;
            fast = fast->next->next;
        }
        while(fast != NULL && fast->next != NULL && slow != fast);
       
        if(slow != fast){
            return NULL;
        }
        
        slow = head;

        int i = 0;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
       
    }
};