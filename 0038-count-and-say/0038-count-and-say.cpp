class Solution {
private:
    string rle(string str){
        
        int freq = 1;
        string ans = "";

      
        for(int i = 1; i < str.size(); i++){
            if(str[i] == str[i-1]){
                freq++;
            }
            else{
                ans += (freq + '0');
                ans += str[i-1];
                freq = 1;
            }

        }
       
        ans += (freq + '0');
        ans += str[str.size()-1];
    
        return ans;
    }
public:
    string countAndSay(int n) {
        if(n == 1)return "1";
        if(n == 2)return "11";

        
        // return rle("21");
        return rle(countAndSay(n-1));
    }
};