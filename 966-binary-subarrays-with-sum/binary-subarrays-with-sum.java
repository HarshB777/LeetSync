class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        HashMap<Integer,Integer> hm = new HashMap<>();

        int cnt = 0;

        int s = 0;

        for (int i = 0; i < nums.length; i++)
        {
            s+=nums[i];
            if (s==goal)
            {
                cnt++;
            }
            int find = s-goal;

            if (find < 0)
            {
                hm.put(s,hm.getOrDefault(s,0)+1);
                continue;
            }
            else if (find == 0)
            {
                cnt += hm.getOrDefault(0,0);
            }else
            {
                if (hm.containsKey(find))
                {
                    cnt += hm.getOrDefault(find,0);
                }
            }
            
            hm.put(s,hm.getOrDefault(s,0)+1);

        }

        return cnt;
    }
}