class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> win;
        unordered_map<int,int> los;

        for (auto x: matches)
        {
            win[x[0]]++;
            los[x[1]]++;
        }
        
        vector<vector<int>> ans(2);
        for (auto x: win)
        {
            int ele = x.first;
            
            if (los.find(ele) == los.end())
            {
                ans[0].push_back(ele);
            }
        }

        for (auto x: los)
        {
            int ele = x.first;
            int freq = x.second;

            if (freq == 1)
            {
                ans[1].push_back(ele);
            }
        }

        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());



        return ans;
        
    }
};