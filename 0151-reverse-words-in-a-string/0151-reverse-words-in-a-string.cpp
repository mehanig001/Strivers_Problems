class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";
        int si = 0;
        int ei = s.size()-1;
        while(s[si] == ' ')si++;
        while(s[ei] == ' ')ei--;
        string curr = "";


        for(int i = si; i <= ei+1; i++){
            if(s[i] == ' ' || i == ei+1){
                if(ans.size() && ans[ans.size()-1] != ' ')
                ans += " ";
                reverse(curr.begin(), curr.end());
                ans += curr;
                curr = "";
                continue;
            }
            curr += s[i];


        }
        return ans;
    }
};