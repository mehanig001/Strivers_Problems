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
#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        queue<pair<TreeNode* , int>> q;  //idx
        q.push({root,0});
        int min = 0;
        while(!q.empty()){
            int n = q.size();
            int mini = q.front().second;
            for(int i = 0; i < n; i++){
                auto pr = q.front();
                TreeNode *tp = pr.first;
                q.pop();
                int x = pr.second;
                x -= mini;
                // cout<<x<<" "<<mini<<endl;
                // maxi = max(maxi,x-mini+1);
                if(i == n-1)maxi = max(maxi,x+1);
                if(tp->left){
                    q.push({tp->left,2*1ll*x+1});
                }
                if(tp->right){
                    q.push({tp->right,2*1ll*x+2});
                }
            }
            
        }
        return maxi;
    }
};