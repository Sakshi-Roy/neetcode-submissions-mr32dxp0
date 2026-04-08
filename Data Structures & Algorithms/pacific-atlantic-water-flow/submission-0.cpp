class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); 
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        queue<pair<int,int>> qp, qa;

        // Pacific (left + top)
        for(int i = 0; i < m; i++){
            qp.push({i, 0});
            pac[i][0] = true;
        }

        for(int j = 0; j < n; j++){
            qp.push({0, j});
            pac[0][j] = true;
        }

        // Atlantic (right + bottom)
        for(int i = 0; i < m; i++){
            qa.push({i, n-1});
            atl[i][n-1] = true;
        }

        for(int j = 0; j < n; j++){
            qa.push({m-1, j});
            atl[m-1][j] = true;
        }

        vector<pair<int,int>> dirs{
            {0,1}, {0,-1}, {1,0}, {-1,0}
        };

        auto bfs = [&](queue<pair<int,int>>& q, vector<vector<bool>>& visited){
            while(!q.empty()){
                auto [x, y] = q.front(); 
                q.pop();

                for(auto &d : dirs){
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if(nx >= 0 && ny >= 0 && nx < m && ny < n 
                       && !visited[nx][ny] 
                       && heights[nx][ny] >= heights[x][y]){
                        
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        };

        bfs(qp, pac);
        bfs(qa, atl);

        vector<vector<int>> result;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac[i][j] && atl[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};