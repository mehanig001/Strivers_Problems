class Solution {
public:
    bool condn(long long int i, long long int j, long long int k, long long sum){
        long long exp = long(k+j-i)/long(j-i+1);
        return (sum < exp);
    }
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        int i = 0, j = 0;
        long long sum = 0; 
        while(j < n){
            sum += nums[j];
            if(condn(i, j, k, sum)){
                ans+=j-i+1;
                j++;
            }
            else{
                while(i < j && !condn(i, j, k, sum)){
                    sum -= nums[i];
                    i++;
                }
                if(condn(i, j, k, sum))
                    ans += j-i+1;
                // cout<<i<<" "<<j<<" "<<j-i+1<<endl;
                j++;
            }
        }
        return ans;

    }
};