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
    int sz(ListNode* head){
        ListNode* temp = head;
        int s = 0;
        while(temp){
            s++;
            temp = temp->next;
        }
        return s;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Map ka use krke 1st wale ko visited kr denge for second k liye chk kr lenge

        //O(1)
        ListNode *i = headA;
        ListNode *j = headB;

        int a = sz(i);
        int b = sz(j);

        if(a < b){
            swap(i,j);
        }

        int ct = abs(a-b);

        while(ct){
            i = i->next;
            ct--;
        }

        while(i && j){
            if(i == j)return i;
            i = i->next;
            j = j->next;
        }

        return NULL;


    }
};