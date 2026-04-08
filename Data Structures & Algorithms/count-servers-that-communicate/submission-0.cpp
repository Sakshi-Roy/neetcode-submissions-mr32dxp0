class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int , vector<int>> row, col;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    row[i].push_back(j);
                    col[j].push_back(i);
                }
            }
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int result = 0;

        for(int i = 0;i < m; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    int size = 0;
                    while(!q.empty()){
                        auto[r, c] = q.front(); q.pop();
                        size++;

                        for(int nc : row[r]){
                            if(!visited[r][nc]){
                                visited[r][nc] = true;
                                q.push({r, nc});
                            }
                        }

                        for(int nr : col[c]){
                            if(!visited[nr][c]){
                                visited[nr][c] = true;
                                q.push({nr, c});
                            }
                        }
                    }
                    if(size>1) result+=size;

                }
            }
        }

        return result;
    }
};