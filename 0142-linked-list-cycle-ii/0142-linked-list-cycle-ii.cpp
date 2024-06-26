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
        if(head == NULL || head->next == NULL)return NULL;
        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)break;
        }

        ListNode* n = new ListNode(-1);
        if((slow == fast) && slow == head && slow->next == NULL)return NULL;
        if(slow != fast)return NULL;
        slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};