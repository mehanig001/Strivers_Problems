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
    bool isLeftBST(TreeNode* root){
        cout<<root->val<<endl;
        TreeNode* l = root->left;
        while(l->right)l = l->right;
        if(l->val >= root->val)return false;
        return true;
    }
    bool isRightBST(TreeNode* root){
        TreeNode* r = root->right;
        while(r->left)r = r->left;
        if(r->val <= root->val)return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)return true;

        if(root->left == NULL && root->right == NULL)return true;

        if(root->left && root->right)return (isLeftBST(root) && isRightBST(root)) &&  (isValidBST(root->left) && isValidBST(root->right));

        if(root->left == NULL){
            return isRightBST(root) && isValidBST(root->right);
        }

        if(root->right == NULL){
            return isLeftBST(root) && isValidBST(root->left);
        }

        return false;
        
    }

};