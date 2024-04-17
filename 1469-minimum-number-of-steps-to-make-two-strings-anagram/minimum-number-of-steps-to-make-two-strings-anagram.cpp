class Solution {
public:
    int minSteps(string s, string t) {
        int a[26] = {0};
        int n = t.size();

        for (int i = 0; i < n; i++)
        {
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }

        int ans = 0;

        for (int x: a)
        {
            if (x > 0)
                ans += x;
        }


        return ans;

        return 1;
    }
};