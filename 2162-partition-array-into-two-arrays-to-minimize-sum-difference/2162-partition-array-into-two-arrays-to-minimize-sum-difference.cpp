#define ll long long
class Solution {
    
public:
    int minimumDifference(vector<int>& nums) {
        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        ll n = nums.size();
        ll N = n/2;
        vector<vector<ll>> left(N+1), right(N+1);

        for(ll msk = 0; msk < (1LL<<N); msk++){
            ll sz = 0, l = 0, r = 0;
            for(ll i = 0; i < N; i++){
                if(msk & (1LL << i)){
                    sz++;
                    l += nums[i];
                    r += nums[N+i];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        for(auto &v : right){
            sort(v.begin(), v.end());
        }
        ll ans = min(abs((sum - 2*left[N][0])), abs((sum - 2*right[N][0])));
        for(ll sz = 1; sz < N; sz++){
            for(auto &a : left[sz]){
                ll b = (sum-2*a)/2, rsz = N-sz;
                auto itr = lower_bound(right[rsz].begin(), right[rsz].end(), b*1ll);
                if(itr != right[rsz].end()){
                    ans = min(ans, abs(sum - 2*(a + (*itr))));
                }
                if(itr != right[rsz].begin()){
                    auto it = itr;
                    it--;
                    ans = min(ans, abs(sum - 2*(a + (*it))));
                }
            }
        }
        return ans;
    }
};