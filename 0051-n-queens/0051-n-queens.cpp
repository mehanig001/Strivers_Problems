class Solution {
private:
    bool isSafe(vector<string> &board, int i, int col, int n){
        //-----?-------'Q'
        for(int j = 0; j < col; j++){
            if(board[i][j] == 'Q')return false;
        }

        //upper diag
        int r = i-1;
        int c = col-1;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q')return false;
            r--;
            c--;
        }

        r = i+1;
        c = col-1;
        while(r < n && c >= 0){
            if(board[r][c] == 'Q')return false;
            r++;
            c--;
        }

        return true;

    }
    void nQueen(vector<vector<string>> &ans, vector<string> &board, int col, int n){
        if(col == n){
            ans.push_back(board);
        }
        for(int i  = 0; i < n; i++){
            if(isSafe(board,i,col,n)){
                board[i][col] = 'Q';
                nQueen(ans,board,col+1, n);
                board[i][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        string x(n,'.');
        vector<string> board(n,x);

        nQueen(ans, board, 0, n);

        return ans;
    }
};