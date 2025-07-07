class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, n = events.size(), ans = 0;
        for(int num = 0; num <= 1e5; num++){
            while(i < n && events[i][0] <= num){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top() < num)pq.pop();

            if(!pq.empty()){
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};