class Solution {
public:
    bool solve(int low,int high,vector<int>nums)
    {
        if(low==high) return false;
        sort(nums.begin()+low,nums.end()+high-nums.size()+1);
        int count=1;
        int diff=nums[low+1]-nums[low];
        for(int i=low+1;i<high;i++)
        {
            if((nums[i+1]-nums[i])==diff)
                count++;
        }
        if(count==(high-low))
            return true;
        return false;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>v(l.size(),false);
        for(int i=0;i<l.size();i++)
        {
            if(solve(l[i],r[i],nums))
                v[i]=true;
            
        }
        return v;
    }
};