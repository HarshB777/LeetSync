class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        long long n = nums.size();
        
        map<long long,vector<long long>> hm; //freq,val
        unordered_map<long long,long long> m; //val,freq
        vector<long long> ans(n,0);
        for (long long i = 0; i < n; i++)
        {
            long long ele = nums[i];
            long long cnt = freq[i];
            
            if (m.find(ele) != m.end())
            {
                int currf = m[ele];
                auto& vec = hm[currf];
                vec.erase(remove(vec.begin(), vec.end(), ele), vec.end()); 
                if (vec.empty())
                {
                    hm.erase(currf);
                }
            }
            
            m[ele] += cnt;
            hm[m[ele]].push_back(ele);
            
            auto last = hm.rbegin();
            ans[i] = last->first;
        }
        
        return ans;
    }
};