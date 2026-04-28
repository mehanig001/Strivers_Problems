class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for(auto &vc : grid){
            for(auto &val : vc){
                v.push_back(val);
            }
        }

        sort(v.begin(), v.end());
        int maxi = v.back();
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            if((maxi - v[i])%x != 0){
                return -1;
            }
            ans += (maxi - v[i])/x;
        }
        int finalAns = ans;

        for(int i = v.size()-2; i >= 0; i--){
            int rt = v.size()-1-i;
            int lt = i+1;

            int diff = (v[i+1] - v[i])/x;

            ans = ans - (lt * diff) + (rt * diff);
            // cout<<curr<<" ";
            finalAns = min(finalAns, ans);
        }
        return finalAns;
    }
};