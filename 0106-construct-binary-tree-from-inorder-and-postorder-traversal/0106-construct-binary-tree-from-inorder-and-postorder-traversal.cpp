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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)return NULL;
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        int value = root->val;

        //making leftIn and rightIn
        vector<int> leftIn, rightIn;
        int  idx = -1;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == value){
                idx = i;
                continue;
            }
            if(idx == -1)leftIn.push_back(inorder[i]);
            else rightIn.push_back(inorder[i]);
        }

        //making rightPost and leftPost
        vector<int> rightPost(rightIn.size());
        int k = 0;
        for(int j = postorder.size()-2; k < rightPost.size(); j--,k++){
            rightPost[rightPost.size()-1-k] = postorder[j];
        }
        
        vector<int> leftPost(leftIn.size());
        k = 0;
        for(int j = postorder.size()-2-rightPost.size(); k < leftPost.size(); j--,k++){
            leftPost[leftPost.size()-1-k] = postorder[j];
        }

        root->left = buildTree(leftIn,leftPost);
        root->right = buildTree(rightIn,rightPost);

        return root;

    }
};