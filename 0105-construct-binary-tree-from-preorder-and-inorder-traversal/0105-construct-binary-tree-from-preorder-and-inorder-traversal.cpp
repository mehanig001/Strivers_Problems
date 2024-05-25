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

        if(preorder.size() == 0)return NULL;

        TreeNode* root = new TreeNode(preorder[0]);
        int value = preorder[0];
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

        idx = -1;
        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i] == value){
                idx = i;
                break;
            }
        }

        vector<int> leftPre(leftIn.size());
        int k = 0;
        for(int j = idx+1; k < leftIn.size() ; j++,k++){
            leftPre[k] = preorder[j];
        }


        vector<int> rightPre(rightIn.size());
        k = 0;
        for(int j = idx+1+leftIn.size(); k < rightIn.size() ; j++,k++){
            rightPre[k] = preorder[j];
        }

        root->left = buildTree(leftPre,leftIn);
        root->right = buildTree(rightPre,rightIn);

        return root;
       
        
    }
};