class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pre(n+1,0);
        for(auto it : queries){
            pre[it[0]]++;
            pre[it[1]+1]--;
        }

        bool flag = true;
        for(int i = 0; i < n; i++){
            if(i > 0){
                pre[i] += pre[i-1];
            }
            if(pre[i] < nums[i]){
                flag = false;
            }
        }
        return flag;
    }
};