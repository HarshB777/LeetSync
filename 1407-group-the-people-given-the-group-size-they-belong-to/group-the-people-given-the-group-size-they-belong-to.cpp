class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        int n = gs.size();
        if (n==1)
        {
            return {{0}};
        }
        //vector<int> cnt(n+1,0);
        vector<vector<int>> idx(n+1);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            int curr = gs[i];

            //cnt[curr]++;
            idx[curr].push_back(i);

            if (idx[curr].size() == curr)
            {
                ans.push_back(idx[curr]);
                idx[curr].clear();
            }
        }
        
        return ans;
    }
};