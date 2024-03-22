class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int minimum=INT_MAX;
        int maximum=INT_MIN;

        int minInd=-1;
        int maxInd=-1;

        for(int j=0;j<nums.size();j++)
        {
            if(minimum>nums[j])
            {
                minimum=nums[j];
                minInd=j;
            }
            if(maximum<nums[j])
            {
                maximum=nums[j];
                maxInd=j;
            }
        }

        int w1=max(minInd,maxInd)+1;
        int w2=nums.size()-min(minInd,maxInd);
        int w3=(min(minInd,maxInd)+1)+(nums.size()-max(minInd,maxInd));

        return min(min(w1,w2),w3);

    }
};