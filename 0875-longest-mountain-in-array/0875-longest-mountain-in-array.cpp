class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int x = 1, y = 0;
        int ans = 0, flag=0;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > arr[i-1]){
                if(flag){
                    x=2;
                    y=0;
                    flag=false;
                }
                else{
                    x++;
                    y = 0;
                }
                
            }
            else if(arr[i] < arr[i-1]){
                y++;
                flag=true;
            }
            else{
                x = 1;
                y = 0;
            }
            if(x >= 2 && y >= 1)
                ans = max(ans, x + y);
            cout<<i<<" "<<x<<" "<<y<<endl;
        }
        if(ans < 3)return 0;
        return ans;
    }
};