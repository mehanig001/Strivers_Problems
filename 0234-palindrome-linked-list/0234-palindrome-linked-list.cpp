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
    ListNode* rev(ListNode* head){
        if(head == NULL || head->next == NULL)return head;
        ListNode* x = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return x;
    }
    ListNode* findMid(ListNode* head){
        if(head == NULL || head->next == NULL)return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            if(fast->next->next)
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)return true;
        ListNode* mid = findMid(head);
        // cout<<"mid "<<mid->val<<endl;
        ListNode* head2 = rev(mid->next);
        mid->next = NULL;

        ListNode* i = head;
        ListNode* j = head2;

        while(i && j){
            // cout<<i->val<<" "<<j->val<<endl;
            if(i->val != j->val)return false;
            i = i->next;
            j = j->next;
        }

        mid->next = rev(head2);

    
        return true;
      

    }
};