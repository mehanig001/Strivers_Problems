class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto v: matrix){
            auto l = lower_bound(v.begin(),v.end(),target);
            if(l != v.end() && (v[l-v.begin()] == target)){
                return true;
            }
        }
        return false;
    }
};