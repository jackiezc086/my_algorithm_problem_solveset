class Solution {
public:
    int numRookCaptures(vector<vector<char>>& g) {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int sx, sy;
        for(int i = 0; i < 8; i ++){
            for(int j = 0; j < 8; j ++){
                if(g[i][j] == 'R')
                    sx = i, sy = j;
            }
        }

        int res = 0;
        for(int i = 0; i < 4; i ++){
            int x = sx;
            int y = sy;
            while(true){
                x += dx[i], y += dy[i];
                if(x < 0 || x > 7) break;
                if(y < 0 || y > 7) break;
                if(g[x][y] == 'B') break;
                if(g[x][y] == 'p'){
                    res ++;
                    break;
                }
            }
        }

        return res;
    }
};
