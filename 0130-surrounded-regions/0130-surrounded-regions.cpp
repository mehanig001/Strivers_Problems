class Solution {
private:
    void dfs(pair<int,int> pr, vector<vector<char>>& board, vector<vector<int>> &visited, int n, int m){
        int row = pr.first, col = pr.second;
        visited[row][col] = 1;

        int deltaRow[] = {-1,0,1,0};
        int deltaCol[] = {0,-1,0,1};

        for(int i = 0; i < 4; i++){
            int newrow = row + deltaRow[i];
            int newcol = col + deltaCol[i];
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !visited[newrow][newcol] && board[newrow][newcol] == 'O'){
                dfs({newrow,newcol}, board,visited,n,m);
            }
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        //Observation: DFS from boundary 0's can't be converted into X

        //traverse through boundary mark all 0's connected through boundary 0's as visited
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(board[i][j] == 'O' && !visited[i][j]){
                        dfs({i,j}, board, visited, n, m);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j]){
                    board[i][j] = 'X';
                }
                
            }
        }
        return;
    }
};