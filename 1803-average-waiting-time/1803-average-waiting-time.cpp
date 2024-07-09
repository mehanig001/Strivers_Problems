#define ll long long 
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ll fin = 0;
        ll sum = 0;
        for(auto it : customers){
            ll ar = it[0];
            ll t = it[1];

            
            fin = fin + max(0*1ll, ar - fin) + t;

            sum += fin - ar;
            

        }

        return sum / (customers.size() * 1.00000);
    }
}; 