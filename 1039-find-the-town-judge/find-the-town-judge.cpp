class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int>m;
        int i,k=0;
        if(n==1)
            return 1;
        for(i=0;i<trust.size();i++){
            m[trust[i][1]]++;
        }
        for(auto j:m){
            if(j.second==n-1)
            {
                k=j.first;
                break;
            }
        }
        if(k==0)
            return -1;
        for(i=0;i<trust.size();i++){
            if(trust[i][0]==k)
                return -1;
        }
        return k;
    }
};