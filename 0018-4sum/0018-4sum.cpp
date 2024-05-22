#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        ll ctr = nums.size();
        

        for(ll i = 0; i < ctr; i++){
           
            ll curr = nums[i];
          
           
            for(ll j = i+1; j < ctr; j++){
               
                ll req = target -(nums[i]);
                req = req-nums[j];
                ll si = j+1;
                ll ei = ctr-1; 

                while(si < ei){
                    if(nums[si] + nums[ei] == req){
                        s.insert({nums[i], nums[j], nums[si], nums[ei]});
                        si++;
                        ei--;
                    }
                    else if(nums[si]+nums[ei] > req)ei--;
                    else si++;
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());



        return ans;
        
    }
};