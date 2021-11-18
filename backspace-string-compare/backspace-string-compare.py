class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def back(res,c):
                if c!='#': res.append(c)
                elif  res : res.pop()
                return res
        return reduce(back,s,[])==reduce(back,t,[])
                
                
        