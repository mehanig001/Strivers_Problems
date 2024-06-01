/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTItr{
    public:
        stack<TreeNode*> s;
        bool reverse;//for next and 1 for before
        BSTItr(TreeNode *root, bool rev){
            pushAll(root,rev);
            reverse = rev;
        }
        void pushAll(TreeNode *root, bool reverse){
            while(root != NULL){
                s.push(root);
                if(reverse){
                    root = root->right;
                }
                else root = root->left;

            }
        }
        bool hasNext(){
            return !s.empty();
        }
        int next(){
            TreeNode* tp = s.top();
            s.pop();
            if(!reverse)
                pushAll(tp->right,reverse);
            else 
                pushAll(tp->left,reverse);

            return tp->val;
        }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)return false;
        
        BSTItr *l = new BSTItr(root,0);
        BSTItr *r = new BSTItr(root,1);

        int i = l->next();
        int j = r->next();

        while(i != j){
            if(i+j == k)return true;
            else if(i+j < k)i = l->next();
            else j = r->next();
        }

        return false;
        
    }
};