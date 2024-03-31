class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sod = 0;
        int t = x;
        while (t > 0)
        {
            sod += (t%10);
            t/=10;
        }
        
        if (x%sod == 0)
        {
            return sod;
        }
        else
            return -1;
    }
};