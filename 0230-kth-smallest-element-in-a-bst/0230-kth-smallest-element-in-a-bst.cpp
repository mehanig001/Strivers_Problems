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
    int ct = 0;
    void inorder(TreeNode *root, int k, int& ans){
        if(root == NULL)return;
       
        inorder(root->left,k , ans);
        ct++;
        if(ct == k)ans = root->val;
        cout<<root->val<<" ";
        inorder(root->right,k , ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        int ans = 0;
        inorder(root, k, ans);

        return ans;
    }
};