class Solution {
public:
    int maximumLengthSubstring(string s) {
        int m = 0;
        for (int i = 0; i < s.size(); i++)
        {
            unordered_map<char,int> hm;  //hashmap char int java
            for (int j = i; j < s.size(); j++)
            {
                hm[s[j]]++; //increasing value of s[j] in hm
                if (hm[s[j]] > 2)  //if any character in hm's value is > 2, we move to next substr
                {
                    m = max(m,j-i);
                    break;
                }
                m = max(m,j-i+1); //else we continue
            }
        }
        
        return m;
    }
};