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
    int sz = 0;
    ListNode* temp = head;
    while(temp != NULL){
        sz++;
        temp = temp->next;
    }
    return sz;
}
ListNode* curr = NULL;
ListNode* reverseFirstKNodes(ListNode* head, int k){

    if(head == NULL || head->next == NULL)return head;


    // rev only if size is less than k
    
    if(sizeOfLL(head) < k){
        return head;
        cout<<"size "<<sizeOfLL(head);
    }

    //rev

    ListNode* prev = NULL;
    curr = head;
    int ct = k;

   
    while(curr && k){
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        k--;
    }

    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {



        if(head == NULL || head->next == NULL || k == 1)return head;

        ListNode* x = reverseFirstKNodes(head,k);

        if(x != head)
        head->next = reverseKGroup(curr,k);

        
        
        return x;
        
    }
};