class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
       int maxchange = 0;
        int size = grid[0].size();
        for(int i = 0; i<size;i++)
        {
            for(int j = 0; j<size;j++)
            {
                int maxr = 0;
                int maxc = 0;
                for(int k = 0; k<size;k++)
                {
                    if(grid[i][k]>= maxr)
                    {
                        maxr = grid[i][k];
                    }
                }
                for(int l = 0; l<size;l++)
                {
                    if(grid[l][j]>= maxc)
                    {
                        maxc = grid[l][j];
                    }
                }
                int sky = min(maxr,maxc);
                maxchange = maxchange + (sky - grid[i][j]); 
            }
        }
        return maxchange;
    }
};