class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(auto str : strs){
            int i = 0;
            while(i < ans.size() && str[i] == ans[i] )i++;
            cout<<i<<endl;
            ans = ans.substr(0,i);
        }

        return ans;


    }
};