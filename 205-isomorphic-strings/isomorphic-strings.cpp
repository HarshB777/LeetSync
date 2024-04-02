class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_set<char> hs;
        int idx = -1;
        unordered_map<char,int> hm1; //char,idx
        //unordered_map<int,int> hm2; //idx,freq
        vector<int> hm2(s.size());
        int j = 0;
        for (char x: s)
        {
            if (hs.find(x) == hs.end())
            {
                idx++;
                hm1[x] = idx;
            }
            int curr = hm1[x];
            hm2[j] = curr;
            hs.insert(x);
            j++;
        }

        
        

        unordered_map<char,int> um1; //char,idx
        //unordered_map<int,int> um2; //idx, freq
        vector<int> um2(t.size());
        unordered_set<char> us;
        int i = -1;
        j = 0;
        for (char x: t)
        {
            if (us.find(x) == us.end())
            {
                i++;
                um1[x] = i;
            }
            int curr = um1[x];
            um2[j] = curr;
            us.insert(x);
            j++;
        }
        
        
        return (hm2==um2);
    }
};