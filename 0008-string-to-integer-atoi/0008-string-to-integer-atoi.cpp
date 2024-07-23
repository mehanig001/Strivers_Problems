class Solution {
private:
 bool isNum(char n){
    return (n >= '0' && n <= '9');
 }

 
public:
    long long int myAtoi(string s) {
        long long int ans = 0;
        long long int n = s.size();

        //ignore leading spaces
        long long int i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }

        bool isNeg = 0;
        if(i < n && s[i] == '-'){
            isNeg = 1;
            i++;
        }
        else if(i < n && s[i] == '+')i++;

        while(i < n && isNum(s[i]) && s[i] == '0'){
            i++;
        }
        // cout<<" i : "<<i<<endl;
        while(i < n && isNum(s[i])){
            ans = ans*10 + (s[i]-'0');
            if(ans >= INT_MAX + 1ll)break;
            i++;
        }
        if(isNeg){
            ans = -1*ans;
        }
        if(ans < INT_MIN){
            return INT_MIN;
        }
        else if(ans > INT_MAX){
            return INT_MAX;
        }
        return (ans);
    }
};