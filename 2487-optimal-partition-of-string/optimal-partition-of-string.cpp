class Solution {
public:
    int partitionString(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();

        unordered_map<char,int> hm;
        int cnt = 0;
        while (j<n)
        {
            j=i;
            /*
            curr = s
curr = h
curr = k
curr = q
curr = b
curr = y
curr = u
curr = t
curr = d
curr = v
curr = k
break
curr = k
curr = n
curr = y
curr = r
curr = p
curr = j
curr = o
curr = f
curr = 
            */
            while (true)
            {
                char curr = s[j];
                cout<<"curr = "<<curr<<endl;
                if (j==n)
                {
                    cnt++;
                    break;
                }
                if (hm.find(s[j])!=hm.end())
                {
                    cnt++;
                    i = j;
                    hm.clear();
                    cout<<"break"<<endl;
                    break;
                }

                hm[curr]++;
                j++;
                

            }
        }

        return cnt;
    }
};