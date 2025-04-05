class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int sum{};
        for(int i{};i<(1<<n);i++){
            int x{};
            for(int j{};j<n;j++){
                if((i>>j)&1){
                    x^=nums[j];
                }
            }
            sum+=x;
        }
        return sum;
    }
};