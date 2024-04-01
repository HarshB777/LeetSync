class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> win;
        map<int,int> los;

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



        return ans;
        
    }
};