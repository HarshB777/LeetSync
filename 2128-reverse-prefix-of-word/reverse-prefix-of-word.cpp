class Solution {
public:
    string reversePrefix(string word, char ch) {
        int x = -1;
        string ans = "";

        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch && x == -1)
            {
                x = i;
                ans += word[i];
                reverse(ans.begin(),ans.end());
            }
            else
            {
                ans += word[i];
            }
        }

        return ans;
    }
};