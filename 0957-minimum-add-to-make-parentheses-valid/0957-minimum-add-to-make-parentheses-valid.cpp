class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, op = 0;
        for(auto &ch : s){
            if(ch == '('){
                op++;
            }
            else{
                if(op > 0){
                    op--;
                }
                else ans++;
            }
        }
        return abs(ans) + op;
    }
};