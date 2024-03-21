class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>freq(A.size()+1,0);
        vector<int>c(A.size(),0);
        int count = 0;
        for(int i=0;i<A.size();i++){
            freq[A[i]]++;
            if(freq[A[i]]==2) count++;
            freq[B[i]]++;
            if(freq[B[i]]==2) count++;
            c[i] = count;
        }
        return c;
    }
};