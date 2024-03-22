class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        vector<int> v1;
        vector<int> v2;

        int r = m.size();
        int c = m[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (m[i][j] == 0)
                {
                    v1.push_back(i);
                    v2.push_back(j);
                }
            }
        }

        for (int x: v1)
        {
            for (int j = 0; j < c; j++)
            {
                m[x][j] = 0;
            }
        }

        for (int x: v2)
        {
            for (int i = 0; i < r; i++)
            {
                m[i][x] = 0;
            }
        }
    }
};