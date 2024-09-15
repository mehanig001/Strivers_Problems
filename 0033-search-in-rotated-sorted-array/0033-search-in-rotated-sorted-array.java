class Solution {
    public int search(int[] nums, int target) {
        int n=nums.length;
        int ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
               ans=i;
             break;
            }
        }
          int low1=0;
          int high1=ans-1;
          while(low1<=high1){
            int mid=(low1+high1)/2;
            if(nums[mid]==target)return mid;
             if(nums[mid]>target){
                high1=mid-1;
             }
             else{
                low1=mid+1;
             }

          }
          int low2=ans;
          int high2=n-1;
          while(low2<=high2){
            int mid=(low2+high2)/2;
            if(nums[mid]==target)return mid;
             if(nums[mid]>target){
                high2=mid-1;
             }
             else{
                low2=mid+1;
             }

          }
          return -1;
    }
}