class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char k){
        for(int i = 0; i < 9; i++){

            if(i != row && board[i][col] == k)return false;
            if(i != col && board[row][i] == k)return false;

            int smallSqrow = 3*(row/3) + i/3;
            int smallSqcol = 3*(col/3) + i%3;

            if(smallSqrow != row && smallSqcol != col && board[smallSqrow][smallSqcol] == k)return false;

        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n = 9, m = 9;
        
        for(int i  = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '.'){
                    for(char k = '1'; k <= '9'; k++){
                        if(isSafe(board,i,j,k)){
                            board[i][j] = k;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        /*
            kya kya hoga 
            rcrsive f(board)

            find empty cell
            for i = 1 to 9 
                if is Safe put and call recursively
                after recursive call ands pop the ele to backtrack
            
            if we reach to the end return ans;

        */

        solve(board);
        

    }
};