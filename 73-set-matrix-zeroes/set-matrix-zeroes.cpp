class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        

        int r = m.size();
        int c = m[0].size();

        vector<int> v1(r,0);
        vector<int> v2(c,0);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (m[i][j] == 0)
                {
                    v1[i] = 1;
                    v2[j] = 1;
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (v1[i]==1 || v2[j]==1)
                {
                    m[i][j] = 0;
                }
            }
        }
    }
};