class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
         # TC: O(N)
         # SC: O(1)        
        pi,pj=1,1
        res=[1]*len(nums)
        
        for i in range (len(nums)):
                j=-1-i;
                res[i]*=pi; res[j]*=pj;
                pi*=nums[i]; pj*=nums[j];
                
        return res
# simulation
        # nums  ->   3 , 14 , 2 , 1 , 4
        # pi    ->   _ , 1 , 12 , 123 , 1234
        # pi     =   1 , 3 , 42 , 84  , 336
        # pj    ->   2345, 345 , 45 , 5 , _
        # pj    =    112, 8 , 4 , 4 , 1
        
        
        