class Solution {
    void f(int i, vector<int> &v, int curr, int &sum){
        if(i == v.size()){
            sum += curr;
            return;
        }
        curr = curr ^ v[i];
        // cout<<curr<<" ";
        f(i+1, v, curr, sum);
        curr = curr ^ v[i];
        f(i+1, v, curr, sum);

        return;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, curr = 0;
        f(0, nums, curr, ans);
        return ans;
    }
};