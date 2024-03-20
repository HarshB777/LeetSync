class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<int> rm(r,0);
        vector<int> cm(c,0);
        int ex = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int curr = grid[i][j];
                ex += curr;
                rm[i] = max(curr,rm[i]);
                cm[j] = max(curr,cm[j]);
            }
        }

        int s = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                //cout<<min(rm[i], cm[j])<<" ";
                s += min(rm[i], cm[j]);
            }
            cout<<endl;
        }


        return s-ex;
    }
};