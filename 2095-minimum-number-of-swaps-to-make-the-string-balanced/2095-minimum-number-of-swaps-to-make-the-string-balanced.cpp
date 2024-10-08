class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        int i = 0, j = s.size()-1;

        int leftOp = 0;
        
        while(i <= j){
            if(s[i] == '['){
                i++;
                leftOp++;
                continue;
            }

            if(leftOp && s[i] == ']'){
                leftOp--;
                i++;
                continue;
            }
            i++;
        }

        ans = (leftOp+1)/2;

        return ans;
    }
};