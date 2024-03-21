class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<vector<int>> vec(3);

        for (int x: nums)
        {
            if (x < pivot)
            {
                vec[0].push_back(x);
            }
            else if (x == pivot)
            {
                vec[1].push_back(x);
            }
            else
            {
                vec[2].push_back(x);
            }
        }
        vector<int> ans;
        for (int i = 0; i < 3; i++)
        {
            for (int k: vec[i])
            {
                ans.push_back(k);
            }
        }
        vec.clear();

        return ans;
    }
};