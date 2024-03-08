class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

        int i = 0;
        int j = n-1;

        while (i < j)
        {
            char left = s[i];
            char right = s[j];

            if (left==right)
            {
                while (s[i]==s[i+1] && i<j)
                {
                    i++;
                }

                while (s[j]==s[j-1] && i<j)
                {
                    j--;
                }
                i++;
                j--;
            }else
            {
                break;
            }

            
        }
        cout<<i<<" "<<j<<endl;
        if (i>j)
            return 0;
        return j-i+1;
    }
};