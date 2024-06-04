class Solution {
public:
    void bfs(queue<pair<int,int>> q, vector<vector<int>> &ans, vector<vector<int>> &visited, int n, int m){
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};
        int dis = 0;
        while(!q.empty()){
            int N = q.size();
            dis++;
            for(int i = 0; i < N; i++){
                pair<int,int> pr = q.front();
                q.pop();
                int row = pr.first, col = pr.second;
                
                for(int j = 0; j < 4; j++){
                    int newrow = row + delRow[j];
                    int newcol = col + delCol[j];
                    if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !visited[newrow][newcol]){
                        if(ans[newrow][newcol] == 1){
                            ans[newrow][newcol] = dis;
                            visited[newrow][newcol] = 1;
                            q.push({newrow, newcol});
                        }
                    }
                }
            

            }

        }

    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans = mat;
        vector<vector<int>> visited(n, vector<int> (m,0));

        queue<pair<int,int>> q;
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && ans[i][j] == 0){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        bfs(q, ans, visited, n , m);

        return ans;

    }
};