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

private:
    TreeNode* helper(TreeNode *temp){
        TreeNode *LST = temp->left;
        if(LST == NULL){
            return temp->right; 
        }
        TreeNode* i = LST;
        while(i && i->right)i = i->right;
        i->right = temp->right;
        temp->right = NULL;
        return temp->left;
    }
    void searchAndDel(TreeNode *root, int key){
        if(root == NULL)return;
        if(root->left && root->left->val == key){
            root->left = helper(root->left);
            return;
        }
        else if(root->right && root->right->val == key){
            root->right = helper(root->right);
            return;
        }
        else{
            if(root->val > key)searchAndDel(root->left, key);
            else searchAndDel(root->right, key);
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return NULL;
        if(root->val == key)return helper(root);

        searchAndDel(root, key);
        return root;
    }
};