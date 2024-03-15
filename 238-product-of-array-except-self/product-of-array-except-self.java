class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int pre[] = new int[n];
        int suf[] = new int[n];
        Arrays.fill(pre,1);
        Arrays.fill(suf,1);
        int[] ans = new int[n];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i-1]*nums[i-1];
            suf[n-i-1] = suf[n-i]*nums[n-i];
        }

        for (int i = 0; i < n; i++)
        {
            ans[i]=pre[i]*suf[i];
        }
        

        return ans;
    }
}