class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sm = 1;

        unordered_set<int> hs;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == sm)
            {
                for (int j = sm+1; j < INT_MAX; j++)
                {
                    if (hs.find(j)==hs.end())
                    {
                        sm = j;
                        break;
                    }
                }
            }

            hs.insert(nums[i]);
        }

        return sm;
    }
};