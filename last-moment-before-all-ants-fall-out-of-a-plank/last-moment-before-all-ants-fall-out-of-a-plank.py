class Solution:
#         TC: O(1)
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        maxleft= max(left) if len(left)>0 else 0
        minright =min(right) if len(right)>0 else n
        return max(maxleft,n-minright)
# observerd that longest path(distance of right end to leftmost ant / distance of left end to  rightmost ant ) has to be traced by ants any how
        