#define ll long long
class Solution {
public:
    long long minimumSteps(string s) {
        ll n = s.size();
        ll si = 0, ei = n-1;
        ll ans = 0;

        while(si < ei){
            if(s[si] == '0'){
                si++;
            }
            else if(s[ei] == '1'){
                ei--;
            }
            else{
                ans += ei-si;
                si++;
                ei--;
            }
        }

        return ans;
           
    }
};