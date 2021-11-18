class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for i in range (len(nums)):
                temp=abs(nums[i])-1
                if nums[temp]>0:nums[temp] *=-1
        return [i+1 for i in range (len(nums)) if nums[i]>0]