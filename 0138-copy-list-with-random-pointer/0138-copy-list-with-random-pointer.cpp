/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //BruteForce  make unordered_map<Node*,Node*>

        //Optimized duplicacy
        if(head == NULL)return NULL; 
        Node* i = head;

        //inserting duplicates
        while(i){
            Node* nxt = i->next;
            Node* newnode = new Node(i->val);
            i->next = newnode;
            newnode->next = nxt;

            i = nxt;
        }

        //adding random pointers to them
        i = head;
        while(i){
            if(i->random){
                // Node* newrand = new Node(i->random->val);
                i->next->random = i->random->next;
            }
            else{
                i->next->random = NULL;
            }
            i = i->next->next;
        }

        //separating lists
        i = head;
        Node* newhead = i->next;
        Node* j = newhead;
        while(i && j ){
            i->next = i->next->next;

            if(j->next)
                j->next = j->next->next;
            else 
                j->next = NULL;

            i = i->next;
            j = j->next;
        }
      
        return newhead;
    }
};