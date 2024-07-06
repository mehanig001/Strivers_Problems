class Solution {

private:
    string expand(string s, int i, int j){
        string ans = "";

        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
        }

        return s.substr(i+1,j-i-1);

    }
public:
    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++){

            string evenPal = expand(s, i, i+1);
            if(ans.size() < evenPal.size())ans = evenPal;
            string oddPal = expand(s,i,i);
            if(ans.size() < oddPal.size())ans = oddPal;

        }

        return ans;
    }
};