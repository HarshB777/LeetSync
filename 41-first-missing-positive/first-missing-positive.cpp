class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sm = 1;

        unordered_set<int> hs;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == sm)
            {
                cout<<"Inside if: "<<endl;
                for (int j = sm+1; j < INT_MAX; j++)
                {
                    cout<<"j = "<<j<<endl;
                    if (hs.find(j)==hs.end())
                    {
                        cout<<"Unfound: "<<endl;
                        sm = j;
                        break;
                    }
                }
                cout<<" sm = "<<sm<<endl;
            }

            hs.insert(nums[i]);
        }

        return sm;
    }
};