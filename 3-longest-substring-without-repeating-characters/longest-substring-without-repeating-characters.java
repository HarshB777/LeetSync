class Solution {
    public int lengthOfLongestSubstring(String s) {

        HashSet<Character> hs = new HashSet<>();
        int m = 0;
        //abcabcbcbb
        //hs = {b,c,a}

        // . a b. c.a. b. c
        
        int left = 0;
        int right = 0;


        for (right = 0; right < s.length(); right++)
        {
            if (!hs.contains(s.charAt(right)))
            {
                hs.add(s.charAt(right));
                m = Math.max(m,right-left+1);
            }else
            {
                while(hs.contains(s.charAt(right)))
                {
                    hs.remove(s.charAt(left));
                    left++;
                }
                hs.add(s.charAt(right));
            }
        }

        return m;
    }
}