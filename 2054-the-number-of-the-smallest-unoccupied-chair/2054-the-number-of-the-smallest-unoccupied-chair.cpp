#define pii pair<int,int>

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pii> v;
        for(int i = 0; i < times.size(); i++){
            auto vc = times[i];
            v.push_back({vc[0], i});
            v.push_back({vc[1], -1});
        }

        sort(v.begin(), v.end());
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        set<int> free;
        for(int i = 0; i < times.size(); i++)free.insert(i);

        for(int i = 0; i < v.size(); i++){
            int a = v[i].first;
            int d = v[i].second;

           
            while(!pq.empty() && pq.top().first <= a){
                auto tp = pq.top();
                pq.pop();
                free.insert(tp.second);
            }

             if(d == -1){ 
                continue;
            }

            auto it = free.begin();
            pq.push({times[d][1], *it});
            if(d == targetFriend){
                return *it;
            }
            free.erase(it);
            
        }

        return 0;
    }
};