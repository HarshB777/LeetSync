class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        //1 1 1 2 4 4 5 5 5 5
        //2 3 3 5
        int m = Integer.MIN_VALUE;
        int i = 0;
        int j = nums.length - 1;

        while (i<j)
        {
            m = Math.max(m,nums[i]+nums[j]);
            i++;
            j--;
        }

        return m;
    }
}