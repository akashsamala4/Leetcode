class Solution:
    def findKthSmallest(self, coins, k):

        from math import gcd

        def lcm(a, b):
            return a // gcd(a, b) * b

        def count(x):
            ans = 0
            n = len(coins)

            for mask in range(1, 1 << n):
                L = 1
                bits = 0

                for i in range(n):
                    if mask & (1 << i):
                        bits += 1
                        L = lcm(L, coins[i])

                        if L > x:
                            break

                if bits % 2 == 1:
                    ans += x // L
                else:
                    ans -= x // L

            return ans

        low = 1
        high = min(coins) * k

        while low < high:
            mid = (low + high) // 2

            if count(mid) >= k:
                high = mid
            else:
                low = mid + 1

        return low