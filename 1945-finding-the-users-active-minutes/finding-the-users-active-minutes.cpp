class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(logs.begin(),logs.end());
        vector<int> ans(k);
        int s=logs.size();
        int l=logs[0][0],lv=-1;
        int cnt=0;
        bool flag;
        for(int i=0;i<s;++i){
            if(logs[i][0]==l){
                if(logs[i][1]!=lv ){
                    cnt++;
                    lv=logs[i][1];
                    flag=true;
                    l=logs[i][0];
                }
            }
            else{
                ans[cnt-1]++;
                l=logs[i][0];
                lv=logs[i][1];
                cnt=1;
                flag=false;
            }
        }
        if(flag)
            ans[cnt-1]++;
        else
            ans[cnt-1]++;

        return ans;
    }
};