class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

        int p1 = 0;
        int p2 = 0;

        int s1 = n-1;
        int s2 = n-1;
        int k = 0;
        for (k=0; k < s.size(); k++)
        {
            cout<<k<<" ";
        }
        cout<<endl;

        while (p1 < s1)
        {
            s1 = s2;
            p2 = p1;
            if (s[p1]==s[s1])
            {
                //prefix right calculation
                while (s[p2]==s[p1] && p2<s1)
                {
                    p2++;
                }
                p2--;

                //suffix left calculation
                while (s[s1]==s[s2] && s1>p2)
                {
                    s1--;
                }
                s1++;
                cout<<"pre = "<<s[p1]<<" suff = "<<s[s1]<<endl;
                cout<<"p1 = "<<p1<<" p2 = "<<p2<<endl;
                cout<<"s1 = "<<s1<<" s2 = "<<s2<<endl;
                cout<<"***next itr***"<<endl;

                n -= (p2-p1 + s2-s1 + 2);
                if (n==1)
                    break;
            }else
            {
                break;
            }
            p1 = p2+1;
            s2 = s1-1;
        }
        return n;
    }
};