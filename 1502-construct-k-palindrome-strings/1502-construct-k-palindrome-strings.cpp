class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k > n)return false;

        map<char, int> mp;
        for(auto &ch : s){
            mp[ch]++;
        }

        int ctOdd = 0;
        for(auto pr : mp){
            if(pr.second & 1)ctOdd++;
        }
        
        return (ctOdd <= k);

    }
};