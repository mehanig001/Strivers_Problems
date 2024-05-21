class Solution {
public:
    double p(double x, int n){
        if(n == 0)return double(1.00000);
        if(n == 1)return x;
        double ans = pow(x,n/2);
        if(n&1){
            return ans*ans*x;
        }
        else return ans*ans;
    }
    double myPow(double x, int n) {
        bool neg = 0;
        bool ulta = 0;
        if(n&1 && x < 0){
            neg = 1;
        }
        if(n < 0)ulta = 1;

        x = abs(x);
        n = abs(n);

        double ans = p(x,n);
        if(ulta)ans = double(1.00000)/(ans);
        if(neg)ans = -1*ans;
        return ans;
    }
};