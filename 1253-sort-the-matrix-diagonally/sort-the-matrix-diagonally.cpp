class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int k = r-1;
        int curr = mat[k][0];
        vector<vector<int>> ans(r, vector<int> (c));
        while (k >= 0)
        {
            vector<int> temp;

            int z = k;
            int y = 0;

            while (z<r && y<c)
            {
                temp.push_back(mat[z][y]);
                z++;
                y++;
            }
            sort(begin(temp),end(temp));

            z = k;
            y = 0;
            int i = 0;
            while (z<r && y<c)
            {
                ans[z][y] = temp[i];
                i++;
                z++;
                y++;
            }

            k--;
        }
        int y = 1;

        while (y < c)
        {
            vector<int> temp;

            int z = y;
            int x = 0;

            while (x<r && z<c)
            {
                temp.push_back(mat[x][z]);
                z++;
                x++;
            }
            sort(begin(temp),end(temp));

            z = y;
            x = 0;
            int i = 0;
            while (x<r && z<c)
            {
                ans[x][z] = temp[i];
                i++;
                z++;
                x++;
            }

            y++;
        }


        return ans;
    }
};