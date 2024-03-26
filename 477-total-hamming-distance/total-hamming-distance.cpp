class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i <= 30; i++)
        {
            int ones = 0;

            for (int j = 0; j < n; j++)
            {
                if (nums[j]&(1<<i))
                {
                    ones++;
                }
            }

            ans += (ones * (n - ones));
        }

        return ans;
    }
};