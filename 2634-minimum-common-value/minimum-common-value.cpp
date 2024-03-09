class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int common = -1;

        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        while (i < nums1.size() && j < nums2.size()){
            if (nums1[i] < nums2[j])
            {
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                common = nums1[i];
                break;
            }
        }

        return common;
    }
};