class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ans = 0;
        while(k--){
            int curr = pq.top();
            ans += curr;
            pq.pop();
            pq.push((curr+2)/3);
        }
        return ans;
    }
};