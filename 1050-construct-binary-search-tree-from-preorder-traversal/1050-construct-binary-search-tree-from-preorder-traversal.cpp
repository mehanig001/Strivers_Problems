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
    TreeNode* bstFromPreorder(vector<int>&preorder, int si, int ei){
        // cout<<si<<" "<<ei<<endl;
       
        if(si > ei)return NULL;

        int i = si;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        while(i <= ei && preorder[i] < preorder[si])i++;
        if(i>=si && i<=ei+1)
        root->left = bstFromPreorder(preorder,si+1,i-1);
        root->right = bstFromPreorder(preorder,i,ei);

        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorder(preorder, 0, preorder.size()-1);

    }
};