class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> um;
        map<int,vector<char>> hm;

        for (char x: s)
        {
            um[x]++;
        }

        for (auto x: um)
        {
            hm[x.second].push_back(x.first);
        }

        string ans = "";

        for (auto x: hm)
        {
            for (auto y: x.second){
                for (int i = 0; i < x.first; i++)
                {
                    ans += y;
                }
            }
        }


        reverse(ans.begin(),ans.end());

        return ans;

    }
};