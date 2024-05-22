class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //O(NLogN)
        set<int> s(nums.begin(),nums.end());
        int maxi = 0;
        int curr = 0;
        int prev = INT_MAX-1;
        for(auto val : s){
            if(val == prev+1 || prev == INT_MAX-1){
                curr++;
                maxi = max(maxi,curr);
                prev = val;
            }
            else{
                prev = val;
                curr = 1;
            }
        }
        return maxi;
    }
};