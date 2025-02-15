class Solution {
public:
    bool check(int sq, int i){
        if(sq<i || i<0) return false;
        if(sq==i) return true;
        return check(sq/10,i-(sq%10)) || check(sq/100,i-(sq%100)) || check(sq/1000,i-(sq%1000));
    }
    int punishmentNumber(int n) {
        int ans =0;
        for(int i=1;i<=n;i++){
            int sq = i*i;
            if(check(sq,i)){
                ans+=sq;
            }
        }
        return ans;
    }
};