class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mi = INT_MAX;
        int mi_idx = -1;
        int ma = INT_MIN;
        int ma_idx = -1;
        int n = size(nums);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > ma)
            {
                ma = nums[i];
                ma_idx = i;
            }

            if (nums[i] < mi)
            {
                mi = nums[i];
                mi_idx = i;
            }
        }

        cout<<ma<<" "<<ma_idx<<endl;
        cout<<mi<<" "<<mi_idx<<endl;
        if (ma == mi)
        {
            return 1;
        }
        int m1 = min(ma_idx,mi_idx);
        int m2 = max(ma_idx, mi_idx);
        int cnt = 0;
        
        if ((m1+1 != n/2)&&(m1+1) < n-m1)
        {
            cnt += (m1+1);


            if (m2-m1 < n-m2)
            {
                cnt += (m2-m1);
            }
            else
            {
                cnt += (n-m2);
            }
        }
        else
        {
            cnt += n-m1;
        }


        return cnt;
    }
};