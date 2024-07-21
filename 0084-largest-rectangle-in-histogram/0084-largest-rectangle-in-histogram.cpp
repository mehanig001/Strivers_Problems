class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller(n);
        vector<int> rightSmaller(n);

        leftSmaller[0] = -1;
        stack<int> st;
        st.push(0);
        for(int i = 1; i < n; i++){

            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                leftSmaller[i] = -1;
            }
            else{
                leftSmaller[i] = st.top();
            }
            
            st.push(i);
        }

        rightSmaller[n-1] = n;
        while(!st.empty())st.pop();

        st.push(n-1);
        for(int i = n-2; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                rightSmaller[i] = n;
            }
            else{
                rightSmaller[i] = st.top();
            }
            
            st.push(i);
        }

        for(auto val : leftSmaller)cout<<val<<" ";cout<<endl;
        for(auto val : rightSmaller)cout<<val<<" ";cout<<endl;

        
        int maxi = 0;

        for(int i = 0; i < n; i++){
            int curr = (rightSmaller[i]-1 - (leftSmaller[i]+1) + 1) * heights[i];
            maxi = max(maxi, curr);
        }


        return maxi;
        


       

    }
};