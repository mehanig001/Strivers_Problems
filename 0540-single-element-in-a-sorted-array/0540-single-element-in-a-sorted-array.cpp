class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        //sorted ka use nhi kiya kyaa 
        // first occ even and second odd 
        int si = 0, ei = nums.size()-1;

        while(si <= ei){
            int mid = si + (ei-si)/2;
            bool parity = mid%2;
            if(1){
                if(parity == 1 && mid <= nums.size()-2 && nums[mid+1] == nums[mid]){
                    ei = mid-1;
                }
                else if(parity == 1 && mid >= 1 && nums[mid] == nums[mid-1]){
                    si = mid+1;
                }
                else if(parity == 0 && mid <= nums.size()-2 && nums[mid] == nums[mid+1]){
                    si = mid+2;
                }
                else if(parity == 0 && mid >= 1 && nums[mid] == nums[mid-1]){
                    ei = mid-1;
                }
                else{
                    return nums[mid];
                }
            }

        }
        return -1;
    }
};