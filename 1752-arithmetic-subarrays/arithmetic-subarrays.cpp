class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> ans(m,false);

        for (int i = 0; i < m; i++)
        {
            int start = l[i];
            int end = r[i];

            vector<int> temp;
            for (int j = start; j <= end; j++)
            {
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            int diff = temp[1] - temp[0];
            int flag = 1;
            for (int k = 1; k < temp.size()-1; k++)
            {
                if (temp[k+1]-temp[k] != diff)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag == 1)
            {
                ans[i] = true;
            }


        }

        return ans;
    }
};