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
    TreeNode* helper(TreeNode* root){
        if(root == NULL)return NULL;
        
        if(root->left == NULL && root->right == NULL)return NULL;
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL)return root->left;
        else{
            TreeNode* LST = root->left;
            TreeNode* i = LST;
            while(i->right)i = i->right;
            i->right = root->right;
            root->right = NULL;
            return LST;
        }

        
    }
    void searchAndDel(TreeNode* root, int key){
        if(root == NULL)return;
        // cout<<root->val<<" ";
        if(root->left && root->left->val == key){
            root->left = helper(root->left);
            return;
        }
        else if(root->right && root->right->val == key){
            root->right = helper(root->right);
            // cout<<root->val<<" "<<endl;
            return;
           
        }
        if(root->val > key)searchAndDel(root->left,key);
        else searchAndDel(root->right,key);
        
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return NULL;
        if(root->val == key)return helper(root);
        searchAndDel(root,key);

        return root;

    }
};