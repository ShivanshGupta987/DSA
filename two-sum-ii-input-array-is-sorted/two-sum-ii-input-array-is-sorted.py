class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i=0
        j=len(nums)-1
        ls=[]
        while 1:
                if (nums[i]+nums[j]>target): 
                        j=j-1
                elif (nums[i]+nums[j]<target) :
                        i=i+1
                else:
                        ls.append(i+1)
                        ls.append(j+1)
                        break
                
        return ls
        