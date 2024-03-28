class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();

        unordered_map<int,int> hm;
        int maxSize = 1;
        while (j < n)
        {
            if (hm[nums[j]] == k)
            {
                maxSize = max(maxSize, j-i);
                break;
            }
            hm[nums[j]]++;
            j++;
        }

        maxSize = max(maxSize, j-i);

        while (j < n)
        {
            hm[nums[i]]--;
            i++;

            while (j < n)
            {
                if (hm[nums[j]] == k)
                {
                    maxSize = max(maxSize, j-i);
                    break;
                }
                hm[nums[j]]++;
                j++;
            }

        }
        maxSize = max(maxSize, j-i);

        return maxSize;
    }
};