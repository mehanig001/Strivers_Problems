class Solution {
public:
    int f(int i, vector<int> &nums, int ans, int curr){
        if(i == nums.size()){
            return curr == ans;
        }
        int p = f(i+1, nums, ans, curr | nums[i]);
        int np = f(i+1, nums, ans, curr);

        return p + np;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0;
        for(auto &val : nums){
            ans = ans | val;
        }

        

        int ct = 0, curr = 0;

        return f(0, nums, ans, curr);

    }
};