class Solution {
public:
    int binSearch(vector<int> &v, int k, int si, int ei){
        while(si <= ei){
            int mid = si+(ei-si)/2;
            if(v[mid] == k)return mid;
            else if(v[mid] < k)si = mid+1;
            else ei = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pvtIdx = nums.size();

        int si = 1, ei = pvtIdx-1;

        while(si <= ei){
            int mid = si + (ei-si)/2;
            if(nums[mid] < nums[mid-1]){pvtIdx = mid;break;}
            if(nums[mid] >= nums[0])si = mid+1;
            else ei = mid-1;
        }

        if(target >= nums[0]){
            return binSearch(nums,target,0,pvtIdx-1);
        }
        else return binSearch(nums,target,pvtIdx,nums.size()-1);
    }
};