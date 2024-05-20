class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > prevEnd){
                ans.push_back({prevStart,prevEnd});
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
            }
            else{
                prevEnd = max(prevEnd,intervals[i][1]);
            }
        }
        ans.push_back({prevStart,prevEnd});

        return ans;
    }
};