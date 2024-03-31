class Solution {
public:
    long long countSubarrays(vector<int>& a, int x, int y) {
        int n=a.size(),i,j=0,k=0;
        unordered_map<int,int> h;
        long long c=0;
        for(i=0;i<n;i++){
            if(a[i]<x||a[i]>y){
                h.clear();
                j=i+1,k=i+1;
            }
            else{
                if(a[i]==x||a[i]==y){
                    h[a[i]]++;
                }
                if(x==y&&h.size()==1){
                    while(k<i){
                        if(a[k]==x||a[k]==y){
                        h[a[k]]--;
                        if(h[a[k]]==0){
                            h[a[k]]++;
                            break;
                        }
                        }
                        k++;
                    }
                    c+=(k-j+1);
                }
                else if(x!=y&&h.size()==2){
                    while(k<i){
                        if(a[k]==x||a[k]==y){
                        h[a[k]]--;
                        if(h[a[k]]==0){
                            h[a[k]]++;
                            break;
                        }
                        }
                        k++;
                    }
                    c+=(k-j+1);
                }
            }
        }
        return c;
    }
};