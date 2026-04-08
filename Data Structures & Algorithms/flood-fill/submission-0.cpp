class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int original = image[sr][sc];

        if(original == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

        vector<pair<int, int>> dirs = {
            {1,0},
            {0,1},
            {-1, 0},
            {0, -1}
        };

        while(!q.empty()){
            auto[x, y] = q.front();
            q.pop();

            for(auto &d: dirs){
                int nx = x + d.first;
                int ny = y + d.second;

                if(nx>=0 && ny>=0 && nx<m && ny<n && image[nx][ny] == original){
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }

        return image;

    }
};