class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int ans = 0;
        for(char ele = 'A'; ele <= 'Z'; ele++){
            int left = 0, ct = 0;
            for(int right = 0; right < n; right++){
                if(s[right] != ele){
                    ct++;
                }
                while(ct > k && left < right){
                    if(s[left] != ele)ct--;
                    left++;
                }
                // cout<<right-left+1<<endl;
                ans = max(ans, right-left+1);
            }
        }
        return ans;
    }
};

//   A C A B A B B A