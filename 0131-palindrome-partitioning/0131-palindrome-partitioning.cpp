class Solution {
private:
    bool isPalindrome(string str, int si, int ei){
        while(si < ei){
            if(str[si] != str[ei])return false;
            si++;
            ei--;
        }
        return true;
    }
    void rcrsn(vector<vector<string>> &ans, vector<string> &curr, int idx, int n, string s){
        if(idx == n){
            ans.push_back(curr);
            
        }

        for(int i = idx; i < n; i++){
            string left = s.substr(idx, i-idx+1);

            if(isPalindrome(left, 0, left.size()-1)){
                curr.push_back(left);
                rcrsn(ans, curr, i+1, n, s);
                curr.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;

        rcrsn(ans,curr,0, s.size(), s);

        return ans;

    }
};