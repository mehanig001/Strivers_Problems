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
    ListNode* insertAtHead(ListNode* head, int data){
        ListNode* newnode = new ListNode(data);
        if(head == NULL){
            return newnode;
        }
        newnode->next = head;
        head = newnode;
        return newnode;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    //     if(list1 == NULL && list2 == NULL)return NULL;
        
    //     ListNode* i = list1;
    //     ListNode* j = list2;


    //     vector<int> sorted;

    //     while(i != NULL && j != NULL){
    //         if(i->val <= j->val){
    //             sorted.push_back(i->val);
    //             i = i->next;
    //         }
    //         else{
    //             sorted.push_back(j->val);
    //             j = j->next;
    //         }
    //     }
    //     while(i != NULL){
    //         sorted.push_back(i->val);
    //         i = i->next;
    //     }
    //     while(j != NULL){
    //         sorted.push_back(j->val);
    //         j = j->next;
    //     }

    //     ListNode* ans = NULL;
    //     for(int i = sorted.size()-1; i >= 0; i--){
    //         ans = insertAtHead(ans,sorted[i]);
    //     }
    
    //     return ans;

        if(list1 == NULL && list2 == NULL)return NULL;
        
        ListNode* dummy = new ListNode(-1);

        ListNode* i = list1;
        ListNode* j = list2;

        ListNode* itr = dummy;

        while(i != NULL && j != NULL){
            if(i->val <= j->val){
                ListNode* temp = new ListNode(i->val);
                itr->next = temp;
                itr = itr->next;
                i = i->next;
            }
            else{
                ListNode* temp = new ListNode(j->val);
                itr->next = temp;
                itr = itr->next;
                j = j->next;
            }
        }
        while(i != NULL){
            ListNode* temp = new ListNode(i->val);
            itr->next = temp;
            itr = itr->next;
            i = i->next;
        }
        while(j != NULL){
            ListNode* temp = new ListNode(j->val);
            itr->next = temp;
            itr = itr->next;
            j = j->next;
        }

        return dummy->next;


    }
};