class Solution {
public:
    void transpose(vector<vector<int>> &v){
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < i; j++){
                swap(v[i][j],v[j][i]);
            }
        }
        return;
    }
    void swapCols(vector<vector<int>> &v){
        int n = v.size();
        for(int i = 0; i  < n; i++){
            int si = 0, ei = n-1;
            while(si < ei){
                swap(v[i][si], v[i][ei]);
                si++;
                ei--;
            }
        }
        return;    
        
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        swapCols(matrix);
    }
};