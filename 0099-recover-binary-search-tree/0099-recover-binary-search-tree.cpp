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
    TreeNode *first = NULL, *second = NULL, *middle = NULL, *prev = NULL;

    void inorder(TreeNode* root){
        if(root == NULL)return;

        inorder(root->left);

        if(!(first) && (prev) && (root->val < prev->val)){
            first = prev;
            middle = root;
        }
        else if(first && prev && (root->val < prev->val)){
            second = root;
            return;
        }
        prev = root;

        inorder(root->right);

    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        // cout<<(first == NULL)<<(middle == NULL)<<(second == NULL);
        if(second)
        swap(first->val,second->val);
        else if(middle)swap(first->val, middle->val);
    }
};