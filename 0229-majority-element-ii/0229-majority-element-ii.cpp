class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //atmost there can be only two integers whose occurance will be >= n/3+1
        int n = nums.size();
        int x = n/3;
        vector<int> ans;

        int ctr1 = 0, ctr2 = 0;
        int ele1 = -1, ele2 = -1;

        for(int i = 0; i < n; i++){
            if(ele1 == nums[i]){ctr1++;continue;}
            if(ele2 == nums[i]){ctr2++;continue;}
            if(!ctr1){
                if(ele2 != nums[i]){
                    ctr1++;
                    ele1 = nums[i];
                }
            }
            else if(!ctr2){
                if(ele1 != nums[i]){
                    ctr2++;
                    ele2 = nums[i];
                }
            }

            else{
                ctr1--;
                ctr2--;

            }
        }

        cout<<ele1<<" "<<ele2<<" "<<ctr1<<" "<<ctr2<<endl;

        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele1)c1++;
            if(nums[i] == ele2)c2++;
        }
        if(c1>x)ans.push_back(ele1);
        if(c2>x && ele1 != ele2)ans.push_back(ele2);
        

        return ans;
    }
};