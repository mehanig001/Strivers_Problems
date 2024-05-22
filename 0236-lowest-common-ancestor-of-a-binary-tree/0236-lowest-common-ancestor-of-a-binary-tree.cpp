/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*> &v){
    if(root == NULL)return false;
    v.push_back(root);
    if(root == target)return true;
    
    bool l = getPath(root->left,target,v);
    bool r = getPath(root->right,target,v);
    
    if(l || r)return true;
    
    v.pop_back();
    return false;
    
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>  v1;
        vector<TreeNode*>  v2;

        getPath(root,p,v1);
        getPath(root,q,v2);

        unordered_set<TreeNode*> s(v1.begin(),v1.end());
    
        for(int i = v2.size()-1; i >=0; i--){
            if(s.find(v2[i]) != s.end())return v2[i];
        }

        return root;





    }
};