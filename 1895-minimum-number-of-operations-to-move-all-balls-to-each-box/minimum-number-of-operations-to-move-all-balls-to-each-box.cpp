class Solution {
public:
    vector<int> minOperations(string boxes) {
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

        for (int i = 0; i < n; i++)
        {

            for (int x: ahead)
                ans[i] += abs(x-i);
        }

        return ans;
        
    }
};