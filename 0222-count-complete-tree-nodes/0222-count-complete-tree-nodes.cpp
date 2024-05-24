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
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)return 0;

        int lh = 0, rh = 0;

        TreeNode *l = root, *r = root;
        while(l->left){
            l = l->left;
            lh++;
        }
        while(r->right){
            r = r->right;
            rh++;
        }

        if(rh == lh){
            return pow(2,lh+1)-1;
        }
        else{
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
        
    }
};