class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sb(n,0);
        unordered_map<int,int> hm; //key,no of setbits;
        int i = 0;
        for (int x: nums)
        {
            int t = 0;
            int k = x;
            while (x > 0)
            {
                if ((x & 1)!=0)
                    t++;
                x = x>>1;
            }
            sb[i] = t;
            hm[k] = t;
            i++;
        }

        for (auto x: sb)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        
        vector<int> st;
        vector<int> end;

        i = 0;
        int j = 0;

        while (j < n)
        {
            while (j<n-1 && sb[j+1] == sb[j])
            {
                j++;
            }
            st.push_back(i);
            end.push_back(j);
            j++;
            i = j;
        }

        //cout<<"st and end"<<endl;
        for (int i = 0; i < st.size(); i++)
        {
          //  cout<<st[i]<<" "<<end[i]<<endl;
            if (st[i]!=end[i])
            {
                sort(nums.begin()+st[i],nums.begin()+end[i]+1);
            }
        }
        //cout<<"nums"<<endl;
        /*for (auto x: nums)
        {
            cout<<x<<" ";
        }
        cout<<endl;*/

        for (int i = 0; i < n-1; i++)
        {
            if (nums[i+1] < nums[i])
            {
                return false;
            }
        }

        return true;
    }
};