#include<bits/stdc++.h>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)return nums;
        // deque<int> q;
        int n=nums.size();
        vector<int> ans;
        int maxi = INT_MIN;

        map<int,int> freq;
        for(int i=0;i<k;i++){
            // q.push_back((nums[i]));
            maxi = max(maxi,nums[i]);
            freq[nums[i]]++;
        }


        ans.push_back(maxi);

        for(int i = k; i < n; i++){
            int tp = nums[i-k];
            // q.pop_front();
            freq[tp]--;
            if(freq[tp] == 0){
                freq.erase(tp);
            }
            if(maxi == tp){
                
                auto it = freq.end();
                it--;
                
                // while(((*it).second < 1))it--;
                maxi = (*it).first;
                
                
            }
            maxi = max(maxi,nums[i]);
            
            ans.push_back(maxi);
            // q.push_back(nums[i]);
            freq[nums[i]]++;
        }

        return ans;
    }
};