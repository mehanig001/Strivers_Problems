class Solution {

private:
    int solve(vector<int>& arr, int n){
        int maxi = -1;
        int chunk = 0;  

        for(int i = 0; i < n; i++){
            maxi = max(maxi, arr[i]);
            if(maxi <= i){
                chunk++;
            }
        }

        return chunk;

    }

public:
    int maxChunksToSorted(vector<int>& arr) {
        return solve(arr, arr.size());
    }
};