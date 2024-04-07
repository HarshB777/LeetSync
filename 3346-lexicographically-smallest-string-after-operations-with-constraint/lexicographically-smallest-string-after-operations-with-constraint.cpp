class Solution {
public:
    int val(char k)
    {
        return (k-'a'+1);
    }
    
    char x(int k)
    {
        return char(97+k-1);
    }
    string getSmallestString(string s, int k) {
        int i = 0;
        string ans = "";
        int n = s.size();
        int t = k;
        while (i<n && t > 0)
        {
            int curr = val(s[i]);
            //cout<<"curr = "<<curr<<endl;
            /*if ((curr + t) > 26)
            {
                cout<<"In 1: added a"<<endl;
                ans += 'a';
                t -= (27-curr);
                cout<<"t = "<<t<<endl;
            }
            else
            {
                if (t >= curr)
                {
                    cout<<"In 2: added a"<<endl;
                    t -= (curr-1);
                    ans += 'a';
                    cout<<"t = "<<t<<endl;
                }
                else
                {
                    cout<<"In 3: added "<<x(curr-t)<<endl;
                    ans += x(curr-t);
                    t = 0;
                    cout<<"t = "<<t<<endl;
                    
                }
                
            }*/
            int flag = -1;
            if ((curr+t)>26 && t>=curr)
            {
                int d1 = 27-curr;
                int d2 = curr-1;
                
                if (d1 < d2)
                {
                    flag = 1;
                }
                else
                {
                    flag = 2;
                }
            }
            
            
            if (flag == 1)
            {
               // cout<<"In flag = 1: added a"<<endl;
                ans += 'a';
                t -= (27-curr);
                //cout<<"t = "<<t<<endl;
            }
            else if (flag == 2)
            {
                //cout<<"In flag = 2: added a"<<endl;
                t -= (curr-1);
                ans += 'a';
                //cout<<"t = "<<t<<endl;
            }
            else
            {
               if ((curr + t) > 26)
                {
                    //cout<<"In 3-1: added a"<<endl;
                    ans += 'a';
                    t -= (27-curr);
                    //cout<<"t = "<<t<<endl;
                }
                else
                {
                    if (t >= curr)
                    {
                       // cout<<"In 3-2: added a"<<endl;
                        t -= (curr-1);
                        ans += 'a';
                        //cout<<"t = "<<t<<endl;
                    }
                    else
                    {
                       // cout<<"In 3-3: added "<<x(curr-t)<<endl;
                        ans += x(curr-t);
                        t = 0;
                        //cout<<"t = "<<t<<endl;
                    
                    }
                
                } 
            }
            
            i++;
        }
        
        while (i < n)
        {
            ans += s[i];
            i++;
        }
        
        //cout<<"***"<<endl;
        
        
        
        return ans;
    }
};