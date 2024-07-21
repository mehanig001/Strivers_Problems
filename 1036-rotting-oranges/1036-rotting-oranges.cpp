class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<int> visited(n*m,0);
        int ones = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    int node = i*m+j;
                    visited[node] = 1;
                }
                else if(grid[i][j] == 1)ones++;
            }
        }


        while(!q.empty()){
            int N = q.size();
            for(int i = 0; i < N; i++){
                auto pr = q.front();
                q.pop();

                int row = pr.first;
                int col = pr.second;

                int delr[] = {-1,0,1,0};
                int delc[] = {0,1,0,-1};

                for(int k = 0; k < 4; k++){
                    int newr = row + delr[k];
                    int newc = col + delc[k];

                    if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && !visited[newr*m+newc]){
                        q.push({newr,newc});
                        int node = newr * m + newc;
                        visited[node] = 1;
                        ones--;
                    }
                }

            }
            time++;

        }
        if(ones != 0){
            return -1;
        }
        return max(0,time-1);
    }
};