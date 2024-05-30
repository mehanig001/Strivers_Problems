class Solution {
public:

    void rcrsn(vector<int> &v, vector<int> &curr, int k, vector<vector<int>> &ans, int n, int i = 0){
        if(i == n && k == 0)ans.push_back(curr);
        if(i == n)return;

            if(k >= v[i]){
                curr.push_back(v[i]);
                rcrsn(v,curr,k-v[i], ans,n,i);
                curr.pop_back();
            }
        
        rcrsn(v,curr,k,ans,n,i+1);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        
        vector<int> curr;

       
        
        rcrsn(candidates,curr,target,ans, candidates.size());

        return ans;
    }
};