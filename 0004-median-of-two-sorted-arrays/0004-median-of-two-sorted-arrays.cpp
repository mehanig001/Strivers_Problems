#define ll long long

class Solution {
    
public:
    double findMedianSortedArrays(vector<int>& v, vector<int>& v2) {
        if(v.size()>v2.size())swap(v, v2);
        ll n1 = v.size();
        ll n2 = v2.size();
        

        ll si = 0;
        ll ei = n1; //n1 not n1-1 
        double ans = 0;

        while(si <= ei){
            ll i = (si + ei)/2;
            ll j = (n1+n2+1)/2 - i;

            ll min1 = (i == n1) ? 1e12 : v[i];
            ll min2 = (j == n2) ? 1e12 : v2[j];
            ll max1 = (i-1 == -1) ? -1e12 : v[i-1];
            ll max2 = (j-1 == -1) ? -1e12 : v2[j-1];

            if(min2 >= max1 && min1 >= max2){
                if((n1+n2)&1){
                    return max({max1, max2});
                }
                else{
                    cout<<min1<<" "<<min2<<" "<<max1<<" "<<max2<<endl;
                    ans = (max(max1, max2) + min(min1, min2))/2.0;
                    return ans;
                }
            }
            else if(min1 < max2){
                si = i+1;
            }
            else ei  = i-1;
        }
        
        return ans;
    }
};