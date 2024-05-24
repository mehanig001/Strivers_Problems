class Solution {
public:
    int trap(vector<int>& v) {
        int ans = 0;
        int n = v.size();
        
        //Two pointers approach
        int i = 0;
        int j = n-1;

        int l = v[i];
        int r = v[j];

        while(i <= j){
            l = max(l,v[i]);
            r = max(r,v[j]);
            
            if(l < r)
                ans+=(min(l,r) - v[i]),i++;
            else
                ans+=(min(l,r) - v[j]),j--;
        }


        return ans;
    }
    // int trap(vector<int>& v) {
    //     int ans = 0;
    //     int n = v.size();
    //     int leftmax[n], rightmax[n];
    //     leftmax[0] = 0;


    //     for(int i = 1; i < n; i++){
    //         leftmax[i] = max(leftmax[i-1],v[i-1]);
    //     }
    //     rightmax[n-1] = 0;
    //     for(int i = n-2; i >= 0; i--){
    //         rightmax[i] = max(rightmax[i+1],v[i+1]);
    //     }



    //     for(int i = 0; i < n; i++){

    //         if(min(leftmax[i],rightmax[i])-v[i] > 0)
    //         ans += (min(leftmax[i],rightmax[i])-v[i]);
    //     }

    //     return ans;
    // }
};