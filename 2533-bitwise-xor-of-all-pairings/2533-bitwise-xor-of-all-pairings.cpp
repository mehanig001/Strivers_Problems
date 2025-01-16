class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l = 0;
        int x = 0;
        for(auto val : nums2)l ^= val;
        for(auto val : nums1){
            x ^= l;
            if(nums2.size()&1)x ^= val;
        }
        return x;
    }
};