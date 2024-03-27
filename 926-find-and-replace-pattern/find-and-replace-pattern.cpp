class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<int,vector<int>> hm1; //index,frequency
        unordered_map<char,int> hm2; //char,index

        int i = 0, j = 0, n = pattern.size();
        int idx = 0; //idx for characters in maps
        while (j < n)
        {
            j = i;
            char curr = pattern[i];
            int flag = 0;
            if (hm2.find(curr)!=hm2.end())
            {
                flag = 1;
            }

            while (j < n && pattern[j]==curr)
            {
                if (flag == 1)
                {
                    int curridx = hm2[curr];
                    hm1[curridx].push_back(j);
                }
                else
                {
                    hm2[curr] = idx;
                    idx++;
                    hm1[hm2[curr]].push_back(j);
                    flag = 1;
                }

                j++;
            }

            i = j;
        }
        vector<string> ans;
        for (string s: words)
        {
            unordered_map<int,vector<int>> um1; //index,frequency
            unordered_map<char,int> um2; //char,index

            int i1 = 0, j1 = 0, n1 = s.size();
            int idx1 = 0; //idx for characters in maps
            while (j1 < n1)
            {
                j1 = i1;
                char curr = s[i1];
                int flag = 0;
                if (um2.find(curr)!=um2.end())
                {
                    flag = 1;
                }

                while (j1 < n1 && s[j1]==curr)
                {
                    if (flag == 1)
                    {
                        int curridx = um2[curr];
                        um1[curridx].push_back(j1);
                    }
                    else
                    {
                        um2[curr] = idx1;
                        idx1++;
                        um1[um2[curr]].push_back(j1);
                        flag = 1;
                    }

                    j1++;
                }

                i1 = j1;
            }

            if (hm1.size() == um1.size())
            {
                if (hm1 == um1)
                {
                    ans.push_back(s);
                }
            }
        }


        return ans;


        
    }
};