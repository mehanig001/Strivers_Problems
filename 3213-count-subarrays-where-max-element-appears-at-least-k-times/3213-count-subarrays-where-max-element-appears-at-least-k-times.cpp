class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        int ct = 0, j = 0;
        for(int i = 0; i < n; i++){
            while(ct < k && j < n){
                if(nums[j] == maxi)ct++;
                j++;
            }
            if(ct == k){
                ans += n-(j-1);
            }
            if(nums[i] == maxi)ct--;
        }
        return ans;
    }
};