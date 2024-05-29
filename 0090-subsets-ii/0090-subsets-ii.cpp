class Solution {
public:
    void subsets(vector<int> &v, vector<vector<int>> &ans, vector<int> curr, int n, int i = 0){
        ans.push_back(curr);
        for(int idx = i; idx < n; idx++){
            if(idx != i && v[idx] == v[idx-1])continue;
            curr.push_back(v[idx]);
            subsets(v, ans, curr, n, idx+1);
            curr.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        subsets(nums, ans, curr, nums.size());

        return ans;
    }
};