class Solution:
        # N-> len(nums)
        # K -> avg size of possible solution list inside "ans" list
        # TC: O(K*(2^N))
        # x -> No. of the possible combination
        # SC: (K*x)
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
        ans=[]
        temp=[]
        nums.sort()
        
        def rec(target,ind):
                if(target==0):
                        ans.append(temp[:])
                        return
                
                for i in range (ind,len(nums)):
                        if(nums[i]>target):
                                return
                        if(i==ind or nums[i]!=nums[i-1] ):                                
                                temp.append(nums[i])
                                rec(target-nums[i],i+1)
                                temp.pop()
                        
        
        rec(target,0)
        return ans
        