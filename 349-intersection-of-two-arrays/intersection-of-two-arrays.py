class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:

        x=set()
        nums1.sort()
        nums2.sort()

        p1=0
        p2=0

        while (p1<len(nums1) and p2<len(nums2)):
            if (nums1[p1]<nums2[p2]):
                p1+=1
            elif (nums1[p1]>nums2[p2]):
                p2+=1
            else:
                x.add(nums1[p1])
                p1+=1
        

        x=list(x)


        return x