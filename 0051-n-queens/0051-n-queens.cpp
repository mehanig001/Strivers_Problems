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
        c = col+1;
        while(r < n && c < n){
            if(board[r][c] == 'Q')return false;
            r++;
            c++;
        }

        return true;

    }
    bool isSafe2(vector<string> &board, int i, int col, int n, vector<int> &leftRow, vector<int> &leftUpper, vector<int> &leftLower){
        //using short tricks hashing and formula to chk leftUpper and leftLower Diagonals

        if(leftRow[i] || leftLower[i+col] || leftUpper[n-1+col-i] )return false;
        return true;

    }
    void nQueen(vector<vector<string>> &ans, vector<string> &board, int col, int n, vector<int> &leftRow, vector<int> &leftUpper, vector<int> &leftLower){
        if(col == n){
            ans.push_back(board);
        }
        for(int i  = 0; i < n; i++){
            if(isSafe2(board,i,col,n, leftRow, leftUpper, leftLower)){
                board[i][col] = 'Q';
                leftRow[i] = 1; leftLower[i+col] = 1; leftUpper[n-1+col-i] = 1;
                nQueen(ans,board,col+1, n, leftRow, leftUpper, leftLower);
                board[i][col] = '.';
                leftRow[i] = 0; leftLower[i+col] = 0; leftUpper[n-1+col-i] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        string x(n,'.');
        vector<string> board(n,x);
        
        vector<int> leftRow(n,0), leftUpper(2*n-1,0), leftLower(2*n-1,0);
        nQueen(ans, board, 0, n, leftRow, leftUpper, leftLower);

        return ans;
    }
};