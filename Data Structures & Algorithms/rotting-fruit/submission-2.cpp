class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
          int m = grid.size();
    int n = grid[0].size();

    queue<pair<int,int>> q;
    int fresh = 0;

    // Step 1: initialize
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 2)
                q.push({i, j});
            else if(grid[i][j] == 1)
                fresh++;
        }
    }

    if(fresh == 0) return 0;

    int minutes = 0;

    vector<pair<int,int>> dirs = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };

    // Step 2: BFS
    while(!q.empty())
    {
        int size = q.size();
        bool changed = false;

        for(int i = 0; i < size; i++)
        {
            auto [x, y] = q.front();
            q.pop();

            for(auto &d : dirs)
            {
                int nx = x + d.first;
                int ny = y + d.second;

                if(nx >= 0 && ny >= 0 && nx < m && ny < n 
                   && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                    changed = true;
                }
            }
        }

        if(changed) minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}
};
