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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //identify which chain is longer and difference in length
        ListNode *i = headA, *j = headB;
        while(i && j){
            i = i->next;
            j = j->next;
        }

        int diff = 0;
        if(i){
            while(i){
                i = i->next;
                diff++;
            }

            i = headA;
            j = headB;
            while(diff){
                i = i->next;
                diff--;
            }
        }
        else{
            while(j){
                j = j->next;
                diff++;
            }
            i = headA;
            j = headB;
            while(diff){
                j = j->next;
                diff--;
            }
        }
        while(i && j && i != j){
                i = i->next;
                j = j->next;
            }
            if(i == j)return i;
            else return NULL;

    }
};