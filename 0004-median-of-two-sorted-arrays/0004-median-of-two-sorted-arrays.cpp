#define ll long long

class Solution {
    
public:
    double findMedianSortedArrays(vector<int>& v, vector<int>& v2) {
        if(v.size()>v2.size())swap(v, v2);
        ll n1 = v.size();
        ll n2 = v2.size();
        

        ll si = 0;
        ll ei = n1; //n1 not n1-1 
        ll i = si+(ei-si)/2;
        
        int ans;

        while(si<=ei){
            i = si+(ei-si)/2; //let i be mid always in v
            
            ll j = ((n1+n2+1)/2)-i; //so that no of elements in left are equal to right

            ll min1 = (i == n1)?INT_MAX*1LL : v[i];
            ll max1 = (i == 0)?INT_MIN*1LL : v[i-1];
            ll min2 = (j == n2)?INT_MAX*1LL : v2[j];
            ll max2 = (j == 0)?INT_MIN*1LL : v2[j-1];

            if(max1 <= min2 && max2 <= min1){
                if((n1+n2)%2 == 0){
                    ans = double((max(max1,max2)+min(min1,min2))/2.0);
                    return double((max(max1,max2)+min(min1,min2))/2.0);
                }
                else{
                    ans = double(max(max1,max2));
                    return double(max(max1,max2));

                }
            }
            else if(max1 > min2){
                ei = i-1;
            }
            else{
                si = i+1;
            }

        }
    return ans;
    }
};