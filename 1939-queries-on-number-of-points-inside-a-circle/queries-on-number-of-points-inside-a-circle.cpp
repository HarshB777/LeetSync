class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = points.size();
        int q = queries.size();
        vector<int> ans(q,0);

    
       
        for (int z = 0; z < n; z++)
        {
            int cx = points[z][0];
            int cy = points[z][1];

            for (int j = 0; j < q; j++)
            {
                int x = queries[j][0];
                int y = queries[j][1];
                int r = queries[j][2];

                if (pow(cx-x,2) + pow(cy-y,2) <= pow(r,2))
                {
                    ans[j]++;
                }
            }

        }

        return ans;


    }
};