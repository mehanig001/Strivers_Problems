class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int i, int j, char ch){
        for(int row = 0; row < board.size(); row++){
            if(board[row][j] == ch && i != row){
                return false;
            }
        }
        for(int col = 0; col < board[0].size(); col++){
            if(board[i][col] == ch && j != col){
                return false;
            }
        }
        int matRow = (i/3)*3, matCol = (j/3)*3;
        for(int k = 0; k < 3; k++){
            for(int del = 0; del < 3; del++){
                int ii = matRow + k, jj = matCol + del;
                if(ii != i && jj != j && board[ii][jj] == ch)return false;
            }
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