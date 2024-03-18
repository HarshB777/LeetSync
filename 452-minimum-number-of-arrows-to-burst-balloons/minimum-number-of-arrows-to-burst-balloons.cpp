class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        int n=a.size(),i,d=0,c;
        for(i=0;i<n;i++){
            swap(a[i][0],a[i][1]);
        }
        sort(a.begin(),a.end());
        c=a[0][0];
        d=1;
        for(i=1;i<n;i++){
                if(c<a[i][1]){
                    d++;
                    c=a[i][0];
                }
            }
        return d;
    }
};