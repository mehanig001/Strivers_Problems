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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> inorderLeft;
        vector<int> inorderRight;
        bool flip = 1;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == preorder[0]){
                flip = 1-flip;
                continue;
            }
            if(flip)
            inorderLeft.push_back(inorder[i]);
            else inorderRight.push_back(inorder[i]);
        }


        vector<int> preorderLeft;
        vector<int> preorderRight;
        
        int l = inorderLeft.size();
        for(int i = 1; i < preorder.size(); i++){
            if(i <= l){
                preorderLeft.push_back(preorder[i]);
            }
            else preorderRight.push_back(preorder[i]);
        }


        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }
};