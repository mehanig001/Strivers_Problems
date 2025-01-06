class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> left(n), right(n);

        int curr = 0, ct = 0;
        for(int i = 0; i < n; i++){
            curr += ct;
            left[i] = curr;
            if(boxes[i] == '1'){
                ct++;
            }
        }
        curr = 0, ct = 0;
        for(int i = n-1; i >= 0; i--){
            curr += ct;
            right[i] = curr;
            if(boxes[i] == '1'){
                ct++;
            }
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = left[i] + right[i];
        }

        return ans;

    }
};