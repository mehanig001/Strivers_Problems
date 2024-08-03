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
private:
    ListNode* findMid(ListNode* head){
        if(head == NULL || head->next == NULL)return head;
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* merge(ListNode* a, ListNode *b){
        if(!a)return b;
        if(!b)return a;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        if(a->val <= b->val){
            head = tail = a;
            a = a->next;
        }
        else{
            head = tail = b;
            b = b->next;
        }

        while(a && b){
            if(a->val <= b->val){
                tail->next = a;
                tail = a;
                a = a->next;
            }
            else{
                tail->next = b;
                tail = b;
                b = b->next;
            }
        }
        if(a)tail->next = a;
        else tail->next = b;

        return head;
    }
    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL)return head;

        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {
        head = mergeSort(head);
        return head;
    }
};