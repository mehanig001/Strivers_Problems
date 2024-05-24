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
    int sizeOfLL(ListNode* head){
        int s = 0;
        ListNode* temp = head;
        while(temp){
            s++;
            temp = temp->next;
        }
        return s;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)return head;
        int s = sizeOfLL(head);
        int p = k%s;
        int asItIs = s-p;
        ListNode* temp = head;
        while((--asItIs) > 0 && temp){
            temp = temp->next;
        }
        if(temp!= NULL && temp->next != NULL){
            ListNode* UnthPahadKeNeeche = temp->next;
            temp->next = NULL;
            ListNode* itr = UnthPahadKeNeeche;
            while(itr->next)itr = itr->next;
            itr->next = head;
            head = UnthPahadKeNeeche;
        }

        return head;
    }
};