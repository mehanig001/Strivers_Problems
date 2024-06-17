class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = nums;
        do{
            ans.push_back(curr);
            next_permutation(curr.begin(), curr.end());
        }
        while(curr != nums);

        return ans;
    }
};