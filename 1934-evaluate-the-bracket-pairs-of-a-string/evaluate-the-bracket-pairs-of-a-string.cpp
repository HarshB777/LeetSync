class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> hm; //knoweldge key, value

        for (auto x: knowledge)
        {
            hm[x[0]] = x[1];
        }

        string ans = "";
        int n = s.size();
        int i = 0;

        while (i < n)
        {
            if (s[i] == '(')
            {
                i++;
                string temp = "";
                while (s[i]!=')')
                {
                    temp += s[i];
                    i++;
                }
                //next letter after closing bracket

                if (hm.find(temp)==hm.end())
                {
                    ans += "?";
                }
                else
                {
                    ans += hm[temp];
                }
            }
            else
            {
                ans += s[i];
            }

            i++;
        }

        return ans;
    }
};