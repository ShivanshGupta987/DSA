class Solution:
#      TC : O(n)
    def maximumRobots(self, times: List[int], costs: List[int], budget: int) -> int:
        cost = i = 0
        
        d = deque()
        n = len(times)
        for j in range(0,n):
            while d and times[d[-1]] <= times[j]:
                d.pop()
            d.append(j)
            
            cost += costs[j]
            
            if times[d[0]] + (j-i+1)*cost > budget:
                if d[0] == i:
                    d.popleft()
                cost -= costs[i]
                i+=1
        return n-i
        