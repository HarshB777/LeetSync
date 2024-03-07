class Solution {
public:
    int partitionString(string s) {
        int cnt = 0;
        
        unordered_set<char> hs;
        for (int i = 0; i < s.size(); i++)
        {
            if (hs.find(s[i]) == hs.end())
            {
                hs.insert(s[i]);
            }else
            {
                hs.clear();
                cnt++;
                hs.insert(s[i]);
            }
        }

        if (!hs.empty())
            cnt++;
        
        return cnt;
    }
};