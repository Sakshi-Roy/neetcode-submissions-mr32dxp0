class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        vector<pair<int, int>> dirs{
            {1,0}, {0,1}, {-1,0}, {0,-1}
        };

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    grid[i][j] = '0';
                     
                    while(!q.empty()){
                        auto[x, y] = q.front();
                        q.pop();

                        for(auto &d : dirs){
                            int nx = x + d.first;
                            int ny = y + d.second;

                            if(nx >= 0 && ny >= 0 && nx < m && ny < n
                                    && grid[nx][ny] == '1'){
                                        
                                        grid[nx][ny] = '0';
                                        q.push({nx, ny});
                            }
                        }
                    }

                }
            }
        }

        return count;
    }
};
