class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;

        for (char &x: s)
        {
            if (x=='1')
                ones++;
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (ones > 1){
                ans+='1';
                ones--;
            }
            else if (i==s.size()-1)
                ans+='1';
            else{
                ans+='0';
            }
        }

        return ans;
    }
};