class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            mp[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for (auto it : mp) {
            char ch = it.first;
            int cnt = it.second;
            pq.push({cnt, ch});
        }
    
        string ans = "";
        while (pq.size() >= 2) {
            auto [cnt, ch] = pq.top();
            pq.pop();
            ans += ch;
            if (!pq.empty()) {
                auto [cnt1, ch1] = pq.top();   
                pq.pop();
                ans += ch1;
                if (cnt1 - 1 > 0) {
                    pq.push({cnt1 - 1, ch1});
                }
            }
            if (cnt - 1 > 0) {
                pq.push({cnt - 1, ch});
            }
            
        }
        if(!pq.empty()){
             auto [cnt,ch]=pq.top();
             if(cnt>1){
                return "";
             }else{
                ans+=ch;
             }
        }
       return ans;
    }
};