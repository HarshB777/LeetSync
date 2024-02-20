class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedSum = 0;
        int actualSum = 0;
        
        int n = nums.size();
        expectedSum = ((n)*(n+1))/2;

        for (auto x: nums)
        {
            actualSum += x;
        }


        return expectedSum - actualSum;

    }
};