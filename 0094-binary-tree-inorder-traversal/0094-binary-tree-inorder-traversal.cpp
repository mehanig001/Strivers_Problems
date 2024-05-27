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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == NULL)return ans;

        //SC   O(1)  Moore's traversal

        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                // cout<<curr->val<<" ";
                ans.push_back(curr->val);
                curr = curr->right;
                continue;
            }

            TreeNode* leftSubtree = curr->left;
            TreeNode* rightmostOfLST = curr->left;
            bool pahleSe = 0;
            while(rightmostOfLST->right){
                if(rightmostOfLST->right == curr){
                    pahleSe = 1;
                    rightmostOfLST->right = NULL;
                    // cout<<curr->val<<" ";
                    ans.push_back(curr->val);
                    curr = curr->right;
                    break;
                }
                rightmostOfLST = rightmostOfLST->right;
      
            }
            if(!pahleSe){
                rightmostOfLST->right = curr;
                curr = curr->left;

            }
        }
        
        return ans;

    }
};