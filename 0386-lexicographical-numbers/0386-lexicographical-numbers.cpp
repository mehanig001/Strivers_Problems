class Solution {
public:
    void push(vector<int> &ans, int l, int r){
        for(int i = l; i <= r; i++){
            ans.push_back(i);
        }
    }

    int countDigits(int n){
        return to_string(n).size();
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        int curr = 1;
        for(int i = 1; i <= n; i++){
            
            ans.push_back(curr);

            if(curr*10 <= n){
                curr = curr*10;
            }
            else{
                while(curr >= n || curr % 10 == 9){
                    curr = curr/10;
                }
                curr++;
            }


        }

        return ans;
    }
};