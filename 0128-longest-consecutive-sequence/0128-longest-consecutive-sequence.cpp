class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //O(NLogN)
        unordered_set<int> s(nums.begin(),nums.end());
        int maxi = 0;
        int curr = 0;
        
        for(auto val : s){
            //wo starting ele ho to hi chk krenge
            if(s.find(val-1) == s.end()){
                curr++;
                int x = val;
                while(s.find(x+1) != s.end()){
                    x++;
                    curr++;
                    maxi = max(curr,maxi);
                }
                maxi = max(curr,maxi);

                curr = 0;
            }
        }
        return maxi;
    }
};