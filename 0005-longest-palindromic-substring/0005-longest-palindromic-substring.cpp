class Solution {

private:
    string expand(string s, int i, int j){
        string ans = "";
        int n = s.size();
        int len = (i == j);

        if(i == j){
            i--;
            j++;
        }
        while(i >= 0 && j < n){
            if(s[i] == s[j]){
                len += 2;
                i--;
                j++;
            }
            else{
                break;
            }
        }
        ans = s.substr(i+1, (j-i-1));

        return ans;
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            string oddLen = expand(s, i, i);
            string evenLen = expand(s, i, i+1);

            if(oddLen.size() > ans.size())ans = oddLen;
            if(evenLen.size() > ans.size())ans = evenLen;

        }

        return ans;
    }
};