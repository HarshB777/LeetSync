class Solution {
public:
    long long sumn(int n)
    {
        long long x = n;
        return ((x)*(x+1))/2;
    }
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        while (i<n && j < n)
        {
            while (i<n-1 && nums[i+1]==nums[i])
                i++;
            
            j = i;
            while (j<n-1 && nums[j+1]!=nums[j])
            {
                j++;
            }
            if (j-i+1 == n)
                return sumn(n);
            if (j-i!= 0 && j-i!=n-1)
                ans += sumn(j-i);
            
            i = j+1;
        }
        
        return ans+n;
    }
};