#define ll long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<ll> suff0(n, 0);
        vector<ll> pre1(n, 0);

        suff0[n-1] = grid[0][n-1];
        for(ll i = n-2; i >= 0; i--){
            suff0[i] = suff0[i+1] + grid[0][i];
        }

        pre1[0] = grid[1][0];
        for(ll i = 1; i < n; i++){
            pre1[i] = pre1[i-1] + grid[1][i];
        }


        ll minOfMax = 1e18;
        ll idx = -1;
        for(ll i = 0; i < n; i++){
            ll right = (i == n-1) ? 0 : suff0[i+1];
            ll left = (i == 0) ? 0 : pre1[i-1];
            ll maxi = max(left, right);
            if(minOfMax > maxi){
                minOfMax = maxi;
                idx = i;
            }
        }

        ll right = (idx == n-1) ? 0 : suff0[idx+1];
        ll left = (idx == 0) ? 0 : pre1[idx-1];
        ll maxi = max(left, right);

        return maxi;


    }
};