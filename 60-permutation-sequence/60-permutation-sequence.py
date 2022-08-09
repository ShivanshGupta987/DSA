class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        num = []
        ans = ''
        fact = 1
        
        for i in range (1,n):
            fact *= i
            num.append(i);
        
        num.append(n);
        k-=1
        
        while True:
            ans += str(num[k//fact])
            del num[k//fact]
            if(len(num)==0):
                break
            k %=fact;
            fact = fact//len(num)
            
        return ans
        
        
        