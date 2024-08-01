class Solution {
private:
public:
    int helper(string s, int i, map<char,pair<int,int>> m){
        int right = m[s[i]].second;
        for(int j = i; j <= right; j++){
            if(m[s[j]].first < i){
                return -1;
            }
            right = max(right, m[s[j]].second);
        }
        return right;
    }

    vector<string> maxNumOfSubstrings(string s) {
        map<char,pair<int,int>> m;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]].second = i;
            }
            else{
                m[s[i]].first = i;
                m[s[i]].second = i;
            }
        }

        vector<string> ans;
        
        int rgt = -1;
        for(int idx = 0; idx < s.size(); idx++){
            char ch = s[idx];
            int i = m[ch].first;
            int j = m[ch].second;

            if(i == idx){
                int right = helper(s,i,m);
                if(right != -1){
                    if(i <= rgt)ans.pop_back();
                    rgt = right;
                    ans.push_back(s.substr(i,rgt-i+1));
                }
            }

        }

        return ans;


    }
};