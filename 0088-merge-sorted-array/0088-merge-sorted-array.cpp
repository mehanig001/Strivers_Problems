class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int k = 0;

        int i = 0, j = 0;

        while(i< m && j < n){
            if(nums1[i] <= nums2[j]){
                k++;
                i++;
            }
            else{
                swap(nums1[i],nums2[j]);
                sort(nums2.begin(),nums2.end());
                i++;
            }
        }
        while(j < n){
            nums1[i++] = nums2[j++];
        }

    }
};