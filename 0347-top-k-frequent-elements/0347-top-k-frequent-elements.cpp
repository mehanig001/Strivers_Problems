class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto pr : mp){
            pq.push({pr.second, pr.first});
        }

        vector<int> ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};