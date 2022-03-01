import numpy as np
# TC : O(log N)
class Solution(object):
    def knightDialer(self, N):
        """
        :type n: int
        :rtype: int
        """
        mod = 10**9 + 7
        if N == 1: return 10
        M = np.matrix([[0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
                       [0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
                       [0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
                       [0, 0, 0, 0, 1, 0, 0, 0, 1, 0],
                       [1, 0, 0, 1, 0, 0, 0, 0, 0, 1],
                       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                       [1, 1, 0, 0, 0, 0, 0, 1, 0, 0],
                       [0, 0, 1, 0, 0, 0, 1, 0, 0, 0],
                       [0, 1, 0, 1, 0, 0, 0, 0, 0, 0],
                       [0, 0, 1, 0, 1, 0, 0, 0, 0, 0]])
        res, N = 1, N - 1
        while N:
            if N % 2: res = res * M % mod
            M = M * M % mod
            N /= 2
        return int(np.sum(res)) % mod
        