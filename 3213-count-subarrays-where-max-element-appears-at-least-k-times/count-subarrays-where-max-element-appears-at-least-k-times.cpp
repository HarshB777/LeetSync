class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0;
        for (int x: nums)
        {
            mx = max(mx,x);
        }

        long long ans = 0;
        int cnt = 0;
        int i = 0;
        int n = nums.size();
        for (int j = 0; j < n; j++)
        {
            cnt += (nums[j]==mx);

            while (cnt >= k)
            {
                cnt -= (nums[i] == mx);
                i++;
            }
            ans += i;
        }

        


        return ans;
    }
};