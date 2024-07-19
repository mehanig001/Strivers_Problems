class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> nxt;
        int n = nums2.size();

        stack<int> st;
        st.push(nums2[n-1]);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                nxt[nums2[i]] = -1;
            }
            else{
                nxt[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            ans[i] = nxt[nums1[i]];
        }

        return ans;
    }
};