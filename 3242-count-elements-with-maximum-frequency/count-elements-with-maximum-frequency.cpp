class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101,0);
        int m = 0;
        for (int x: nums)
        {
            freq[x]++;

            m = max(freq[x],m);
        }
        int cnt = 0;
        for (int i = 1; i<=100; i++)
        {
            if (freq[i] == m)
                cnt += m;
        }

        return cnt;

    }
};