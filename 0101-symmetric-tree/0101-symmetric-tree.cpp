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
bool isPalindrome(vector<int> &v){
    int si = 0;
    int ei = v.size()-1;

    while(si < ei){
        if( v[si] != v[ei] )return false;
        si++;
        ei--;
    }
    return true;
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)return true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> curr;

            for(int i = 0; i < n; i++){
                TreeNode* tp = q.front();
                q.pop();
                if(tp == NULL)curr.push_back(-101);
                else
                curr.push_back(tp->val);
                    if(tp)
                    q.push(tp->left);
                
                    if(tp)
                    q.push(tp->right);
                
            }
            for(auto val : curr)cout<<val<<" ";
            cout<<endl;
            if(!isPalindrome(curr))return false;
        }
        
        return true;
    }
};