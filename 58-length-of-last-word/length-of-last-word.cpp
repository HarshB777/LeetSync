class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;

        int i = s.size()-1;

        for (i = i; i >= 0; i--)
        {
            if (s[i]!=' '){
                len++;
            }
            else if (len!=0)
                break;
        }

        return len;
    }
};