class Solution {
private:
    char shift(char x, int place){
        place %= 26;
        if(place >= 0){
            return char((x-'a' + place)%26 +'a');
        }
        else return char((x-'a' + place + 26)%26 + 'a');
    }
    
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> pre(n+1,0);

        for(auto it : shifts){
            if(it[2] == 1){
                pre[it[0]] += 1;
                pre[it[1]+1] -= 1;
            }
            else{
                pre[it[0]] -= 1;
                pre[it[1]+1] += 1;
            }
        }

        for(int i = 1; i <= n; i++){
            pre[i] += pre[i-1];
        }

        // for(auto val : pre)cout<<val<<" ";cout<<endl;

        string ans = "";
        for(int i = 0; i < n; i++){
            ans += shift(s[i], pre[i]);
        }

        return ans;
    }
};