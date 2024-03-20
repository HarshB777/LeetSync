class Solution {
public:
    vector<int> minOperations(string boxes) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> ahead;

        int n = boxes.size();

        for (int i = 0; i < n; i++)
        {
            if (boxes[i] == '1')
            {
                ahead.push_back(i);
            }
        }

        vector<int> ans(n,0);

        /*for (int i = 0; i < n; i++)
        {

            for (int x: ahead)
                ans[i] += abs(x-i);
        }*/

        for (int x: ahead)
        {
            for (int i = 0; i < n; i++)
            {
                ans[i] += abs(x-i);
            }
        }

        return ans;
        
    }
};