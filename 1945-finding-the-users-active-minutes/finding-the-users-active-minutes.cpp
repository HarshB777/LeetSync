class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<int>> hm;
        vector<int> ans(k,0);

        for (auto x: logs)
        {
            hm[x[0]].insert(x[1]);
        }
        for (auto x: hm)
        {
            //cout<<x.first<<' '<<x.second.size()<<endl;
            ans[x.second.size()-1]++;
        }
        return ans;
    }
};