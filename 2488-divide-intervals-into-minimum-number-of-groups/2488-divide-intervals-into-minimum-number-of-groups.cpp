#define ll long long
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>> v;
        for(auto vc : intervals){
            v.push_back({vc[0],0});
            v.push_back({vc[1],1});
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        ll curr = 0;
        for(ll i = 0; i < v.size(); i++){
            if(v[i].second == 0){
                curr++;
                ans = max(ans, curr);
            }
            else{
                curr--;
            }
        }
        return ans;
    }
};