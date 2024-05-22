class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int,int>> v(nums.size());
        for(int i = 0; i < nums.size(); i++){
            v[i].first = nums[i];
            v[i].second = i;
        }
        sort(v.begin(),v.end());
        int si = 0, ei = v.size()-1;

        while(si < ei){
            if(v[si].first+v[ei].first == target){
                ans.push_back(v[si].second);
                ans.push_back(v[ei].second);
                return ans;
            }
            else if(v[si].first + v[ei].first > target)ei--;
            else si++;
        }
        return ans;
    }
};