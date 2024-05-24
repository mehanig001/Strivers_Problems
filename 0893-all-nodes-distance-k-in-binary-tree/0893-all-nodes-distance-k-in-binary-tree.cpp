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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //Marking parents to go upward
        unordered_map<TreeNode*,TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* tp = q.front();
                q.pop();
                if(tp->left){
                    m[tp->left] = tp;
                    q.push(tp->left);
                }
                if(tp->right){
                    m[tp->right] = tp;
                    q.push(tp->right);
                }
            }
        }

        //parents are marked now we have to use visited to check already visited or not to move radially
        while(!q.empty())q.pop();
        

        int dis = 0;
        unordered_set<TreeNode*> s;
        s.insert(target);
        q.push(target);
        vector<int> ans;

        
        while(!q.empty()){
            int n = q.size();
            if(dis == k){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            dis++;
            for(int i = 0; i < n; i++){
                TreeNode *tp = q.front();
                q.pop();
                if(m[tp] && s.find(m[tp]) == s.end()){
                    s.insert(m[tp]);
                    q.push(m[tp]);
                }
                if(tp->left)
                if(s.find(tp->left) == s.end()){
                    s.insert(tp->left);
                    q.push(tp->left);
                }
                if(tp->right)
                if(s.find(tp->right) == s.end()){
                    s.insert(tp->right);
                    q.push(tp->right);
                }
            }
        }
        return ans;
    }
};