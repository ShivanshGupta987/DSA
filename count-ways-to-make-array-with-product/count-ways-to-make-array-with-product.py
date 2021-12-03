primes = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97)
mod = 1000000007
class Solution:
    def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
        res=[]
        def fun(n : int , k: int) -> int :
                sol=1
                for p in primes :
                        if(k%p==0):
                                count =0
                                while(k%p==0):
                                        count = count + 1
                                        k=k/p
                                sol = sol * comb(n-1+count , count)
                if(k!=1): sol= sol*n
                return sol%mod
        return [fun(n,k) for n,k in queries ]