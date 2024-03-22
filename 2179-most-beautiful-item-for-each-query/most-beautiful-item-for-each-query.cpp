class Solution {
public:

    int nearbin(vector<int>& v, int q) {
    int n = v.size();
    int lo = 0;
    int hi = n - 1;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if (v[mid] == q) {
            return q;
        } else if (v[mid] < q) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    if (hi < 0) {
        return -1; // No value less than q
    }
    
    return v[hi]; // Return the closest value less than q
}

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries){
        sort(items.begin(), items.end());
        unordered_map<int,int> hm; //price,maxBeauty till here
        vector<int> prices;
        int maxBeauty = 0;
        int its = items.size();
        for (int i = 0; i < its; i++)
        {
            int currPrice = items[i][0];
            prices.push_back(currPrice);
            maxBeauty = max(maxBeauty,items[i][1]);

            hm[currPrice] = maxBeauty;
        }
        int n = queries.size();
        vector<int> ans(n,0);
        int idx = 0;
        for (int x: queries)
        {
            if (nearbin(prices,x)!=-1)
            {
                ans[idx] = hm[nearbin(prices,x)];
            }
            else
            {
                ans[idx]=0;
            }

            idx++;
        }

        return ans;
    }
};