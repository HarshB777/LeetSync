class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long os = 0;

        for (int x: nums)
        {
            os += x;
        }
        long fs = 0;
        int cnt = 0;
        for (int i = 0; i < n-1; i++)
        {
            os -= nums[i];
            fs += nums[i];

            if (fs >= os)
            {
                cnt++;
            }

        }

        return cnt;
    }
};