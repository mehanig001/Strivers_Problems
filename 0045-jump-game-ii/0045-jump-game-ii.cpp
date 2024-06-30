class Solution {
public:
    int jump(vector<int>& nums) {
        
        int curr = 0, maxi = 0, n = nums.size(), j = 0, prev = 0;

        if(n == 1)return 0;


        j++;
        maxi = nums[0];
        int idx = nums[0];

        for(int i = 1; i < n-1; i++){
          
            int curr = i + nums[i];

            maxi = max(maxi,curr);
            
            if(i >= idx){
                j++;
                idx = maxi;
            }
           

        }

        return j; 

    }
};