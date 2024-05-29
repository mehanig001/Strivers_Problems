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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode = new TreeNode(val);
        if(root == NULL)return newnode;

        TreeNode *curr = root;
        TreeNode *prev = curr;
        while(curr){
            prev = curr;
            if(val < curr->val){
                curr = curr->left;
            }
            else curr = curr->right;
        }

        if(prev){
            if(prev->val > val){
                prev->left = newnode;
            }
            else{
                prev->right = newnode;
            }
        }

        return root;

    }
};