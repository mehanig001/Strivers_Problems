/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;

        //one lie in right and other in left
        if(root->left && root->right){
            if(p->val < root->val && q->val > root->val || p->val > root->val && q->val < root->val ){
               return root;
            }
        }
        if(root->left){
            if(root->val > p->val && root->val > q->val){
                TreeNode* l = lowestCommonAncestor(root->left,p,q);
                if(l)return l;
            }
        }
        if(root->right){
            if(root->val < p->val && root->val < q->val){
                TreeNode* r = lowestCommonAncestor(root->right,p,q);
                if(r)return r;
            }
        }
        return NULL;
        
    }
};