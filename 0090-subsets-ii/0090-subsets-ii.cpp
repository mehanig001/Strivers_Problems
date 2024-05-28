class Solution {
public:
    void subsets(vector<int> &v, set<multiset<int>> &s, multiset<int> curr, int n, int i = 0){
        if(i == n){
            s.insert(curr);
            return;
        }
        subsets(v,s,curr,n,i+1);
        curr.insert(v[i]);
        subsets(v,s,curr,n,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<multiset<int>> s;
        multiset<int> curr;
        subsets(nums, s, curr, nums.size());
        vector<vector<int>> ans;

        for(auto st : s){
            vector<int> v;
            for(auto val: st){
                v.push_back(val);
            }
            ans.push_back(v);
        }

        return ans;
    }
};