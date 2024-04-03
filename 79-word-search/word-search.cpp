class Solution {
public:
void pre(vector<vector<char>>& a,string s,int q,int x,int y,int z,int& p,set<pair<int,int>>& h){
    int i,j,n=a.size(),m=a[0].size(),b[4],c[4];
    if(x==q){
        p=1;
        return ;
    }
    b[0]=0,b[1]=0,b[2]=-1,b[3]=1;
    c[0]=-1,c[1]=1,c[2]=0,c[3]=0;
    for(i=0;i<4;i++){
        if(0<=(y+b[i])&&(y+b[i])<n&&0<=(z+c[i])&&(z+c[i])<m&&h.find({y+b[i],z+c[i]})==h.end()&&s[x]==a[y+b[i]][z+c[i]]){
            h.insert({y+b[i],z+c[i]});
           pre(a,s,q,x+1,y+b[i],z+c[i],p,h);
        }
    }
    h.erase({y,z});
    return;
}
    bool exist(vector<vector<char>>& a, string s) {
        int x=s.size(),i,n=a.size(),m=a[0].size(),j,y=1;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i][j]==s[0]){
                    set<pair<int,int>> h;
                    h.insert({i,j});
                    int p=0;
                    y=1;
                    int e=i,f=j;
                    pre(a,s,x,y,e,f,p,h);
                    if(p==1){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};