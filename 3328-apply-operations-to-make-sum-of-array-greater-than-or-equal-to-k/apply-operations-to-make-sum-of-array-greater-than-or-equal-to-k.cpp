class Solution {
public:
    int minOperations(int k) {
        int st = 1;
        int cnt = 0;
        int mi = k;
        
        mi = min(k-st,mi);
       // cout<<"k/2 = "<<k/2<<endl;
        //cout<<"mi = "<<mi<<endl;
        for (int i = 1; i <= (k/2); i++)
        {
            
            int dir = (i-st);
            int doub = ceil(float(k)/i) - 1;
            
            int curr = dir + doub;
            //cout<<"dir, doub, curr "<<dir<<" "<<doub<<" "<<curr<<endl;
            mi = min(mi, curr);
            //cout<<"mi = "<<mi<<endl;
            
        }
        
        return mi;
    }
};