class Solution {
public:
    bool isv(char v)
    {
        if (v=='A' || v=='E' || v == 'I' || v == 'O' || v == 'U' || v =='a' || v == 'e' || v == 'i' || v == 'o' || v == 'u')
            return true;
        
        return false;
    }
    string sortVowels(string s) {
        vector<char> w;
        unordered_set<int> p;

        for (int i = 0; i < s.size(); i++)
        {
            if (isv(s[i]))
            {
                w.push_back(s[i]);
                p.insert(i);
            }
        }

        sort(w.begin(),w.end());
        reverse(w.begin(),w.end());

        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (p.find(i) != p.end())
            {
                ans += w.back();
                w.pop_back();
            }
            else
            {
                ans += s[i];
            }
        }

        return ans;
    }
};