class Solution {
public:
    int minimumLines(vector<vector<int>>& arr) {
        if(arr.size()==1) return 0; 
        sort(begin(arr),end(arr));
        int n = arr.size();
        int ct=1;

        for(int i=1;i<n-1;i++){
            int x1=arr[i-1][0];
            int y1=arr[i-1][1];
            
            int x2=arr[i][0];
            int y2=arr[i][1];
            
            int x3=arr[i+1][0];
            int y3=arr[i+1][1];
            
            long long slope1 = 1ll*(y2-y1)*(x3-x2);
            long long slope2 = 1ll*(y3-y2)*(x2-x1);
            
            if(slope1!=slope2) ct++;
        }
        
        return ct;
    }
};