class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        //increasing
        int m1 = 0;
        int n = nums.size();
        int i = 0, j = 0;
        
        while (j < n)
        {
            j = i+1;
            while (j<n && nums[j] > nums[j-1])
            {
                j++;
            }
            
            m1 = max(m1,j-i);
            i = j;
        }
        
        int m2 = 0;
        i = j = 0;
        while (j < n)
        {
            j = i+1;
            while (j < n && nums[j] < nums[j-1])
            {
                j++;
            }
            m2 = max(m2,j-i);
            i = j;
        }
        return max(m1,m2);
    }
};