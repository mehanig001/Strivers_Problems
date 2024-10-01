class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        map<int,int> rem;
        for(int i = 0; i < arr.size(); i++){
            int curr = arr[i] % k;
            if(curr < 0) curr += k;
            rem[curr]++;
        }

        bool ans = true;

        for(auto pr : rem){
            if(pr.first == 0){
                if(pr.second & 1)
                    ans = ans & false;
            }
            else{
                int compliment = k-pr.first;
                if(pr.first == compliment){
                    ans = ans & ((pr.second % 2) == 0);
                }
                else 
                ans = ans & (rem[compliment] == pr.second);
            }
        }

        for(auto pr : rem)cout<<pr.first<<" "<<pr.second<<endl;
        
        return ans;
    }   
};