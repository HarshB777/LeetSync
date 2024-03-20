class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        vector<int> ans(n,0);

        vector<int> prev(31,0);
        int l1 = 0;

        for (int b = 0; b < 31; b++)
        {
            if ((1<<b & pref[0])!=0)
            {
                prev[b] = 1;
                l1 = b;
            }
        }

        ans[0] = pref[0];
        for (int i = 1; i < n; i++)
        {
            vector<int> curr(31,0);
            int l2 = 0;
            for (int b = 0; b < 31; b++)
            {
                if ((1<<b & pref[i])!=0)
                {
                    curr[b] = 1;
                    l2 = b;
                }
            }

            
            for (int k = max(l2,l1); k>=0; k--)
            {
                if (curr[k] == 1 && prev[k]==0)
                {
                    ans[i] = ans[i] + (1<<k);
                }
                else if (curr[k] == 0 && prev[k] == 1)
                {
                    ans[i] = ans[i] + (1<<k);
                }
            }


            prev = curr;
            l1 = l2;
        }

        return ans;

    }
};