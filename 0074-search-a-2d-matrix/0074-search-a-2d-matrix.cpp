class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int si = 0;
        int ei = matrix.size() * matrix[0].size() - 1;

        while(si <= ei){
            int i = si + (ei-si)/2;
            int row = i/matrix[0].size();
            int col = i%matrix[0].size();
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target)si = i+1;
            else ei = i-1;
        }
        return false;
    }
};