class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ct = 0;
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];

        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1]+nums[i];
        }
        unordered_map<int, int> m;
        m[0] = 1;

        for(int i = 0; i < n; i++){
            int rem = (pre[i] + 10000*k) % k;
            ct += m[rem];
            m[rem]++;
        }
        return ct;
    }
};