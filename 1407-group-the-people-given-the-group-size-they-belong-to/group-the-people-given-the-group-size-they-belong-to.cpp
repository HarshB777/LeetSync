class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        int n = gs.size();
        if (n==1)
        {
            return {{0}};
        }
        vector<int> cnt(n+1,0);
        vector<vector<int>> idx(n+1);

        for (int i = 0; i < n; i++)
        {
            int curr = gs[i];

            cnt[curr]++;
            idx[curr].push_back(i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i <= n; i++)
        {
            if (idx[i].size()==0)
            {
                continue;
            }

            int k = 0;
            while (k!=idx[i].size())
            {
                vector<int> temp;
                for (int j = k; j < i+k; j++)
                {
                    temp.push_back(idx[i][j]);
                }
                ans.push_back(temp);
                k+=i;
            }
        }
        return ans;
    }
};