class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;

        int cnt = 0;

        for (char x: s)
        {
            if (x=='(')
            {
                cnt++;
            }
            else if (x==')')
            {
                cnt--;
            }

            mx = max(mx,cnt);
        }

        return mx;

    }
};