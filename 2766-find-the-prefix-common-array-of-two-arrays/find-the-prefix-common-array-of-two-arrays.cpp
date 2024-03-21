class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        unordered_map<int,int> hm; //val,freq;
        int n = A.size();
        vector<int> ans(n,0);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            hm[A[i]]++;
            hm[B[i]]++;

            if (hm[A[i]] == 2)
            {
                cnt++;
                hm[A[i]] = 0;
            }

            if (hm[B[i]] == 2)
            {
                cnt++;
                hm[B[i]] = 0;
            }
            ans[i] = cnt;
        }


        return ans;
    }
};