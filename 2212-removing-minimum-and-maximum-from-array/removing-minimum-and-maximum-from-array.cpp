class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        int minIdx = -1;
        int maxIdx = -1, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < minVal)
            {
                minVal = nums[i];
                minIdx = i;
            }

            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                maxIdx = i;
            }
        }

        if (minIdx==maxIdx)
            return 1; //size = 1
        
        //cout<<minVal<<" "<<minIdx<<endl;
        //cout<<maxVal<<" "<<maxIdx<<endl;
        //cout<<endl;

        int min1 = min(minIdx,maxIdx);
        int max1 = max(maxIdx,minIdx);

        //cout<<min1<<" "<<max1<<endl;

        //poss1 - both deleted from front
        int m1 = max1+1;
        //poss2 - one deleted from front, one from behinf
        int m2 = min1+1 + (n-max1);
        //poss3 - both deleted from behind
        int m3 = max(n-min1, n-max1);

        //cout<<m1<<" "<<m2<<" "<<m3<<endl;

        return min(min(m1,m2),m3);

        //return -1;
    }
};