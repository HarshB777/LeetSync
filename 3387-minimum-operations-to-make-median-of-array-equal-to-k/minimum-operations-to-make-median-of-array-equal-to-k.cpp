class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        int mid = n/2;
        
        
        sort(nums.begin(),nums.end());
        
        
        if (nums[mid] == k)
            return 0LL;
        long long ans = 0;
        if (nums[mid] < k)
        {
            int i = mid;
            
            while (i<n && nums[i]<k)
            {
                ans += abs(nums[i]-k);
                i++;
            }
        }
        else
        {
            int i = mid;
            while (i>=0 && nums[i] > k)
            {
                ans += abs(nums[i]-k);
                i--;
            }
        }
        
        
        return ans;
    }
};