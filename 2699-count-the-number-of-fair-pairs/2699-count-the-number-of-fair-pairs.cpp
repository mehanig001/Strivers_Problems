class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long ans = 0;
        int si = 0, ei = n-1;
        while(si < ei){
            if(nums[si] + nums[ei] > upper){
                ei--;
            }
            else if(nums[si] + nums[ei] < lower){
                si++;
            }
            else{
                int l = lower_bound(nums.begin()+si+1, nums.end(), lower - nums[si]) - nums.begin();
                if(l <= ei)
                ans += (ei-l+1);
                si++;
            }
        }

        return ans;
    }
};