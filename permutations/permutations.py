class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans=[]
        
        def backtrack(ind=0 ,end =len(nums)):
                if ind==end:
                        ans.append(nums[:])
                        
                for i in range(ind,end):
                        nums[i], nums[ind] = nums[ind], nums[i]
                        backtrack(ind+1,end)
                        nums[i], nums[ind] = nums[ind], nums[i]
        backtrack()
        return ans

        