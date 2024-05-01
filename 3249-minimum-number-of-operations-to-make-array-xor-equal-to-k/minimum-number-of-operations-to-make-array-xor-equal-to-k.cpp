class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int op = 0;

        for (int x: nums)
        {
            op = op^x;
        }

        vector<int> cntk(31,0);
        vector<int> cntop(31,0);

        for (int b = 0; b < 31; b++)
        {
            if ((op & 1<<b)!=0)
            {
                cntop[b]++;
            }
            if ((k & 1<<b)!=0)
            {
                cntk[b]++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < 31; i++)
        {
            if (cntop[i] != cntk[i])
                cnt++;
        }

        return cnt;

        return op;
    }
};