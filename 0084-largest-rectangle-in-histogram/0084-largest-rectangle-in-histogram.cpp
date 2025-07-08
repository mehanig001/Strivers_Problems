class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                auto j = st.top();
                st.pop();
                ans = max(ans, heights[j] * (st.empty() ? i : i-st.top()-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            auto i = st.top();
            st.pop();
            ans = max(ans, heights[i] * (st.empty() ? n : n-st.top()-1));
        }
        return ans;
    }
};