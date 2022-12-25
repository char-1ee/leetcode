# Python no need to consider signed integer overflows

class Solution:
    def countAnagrams(self, s: str) -> int:
        MOD = 10 ** 9 + 7
        ans = 1
        for word in s.split():
            n = len(word)
            for v in Counter(word).values():
                ans *= comb(n, v)
                ans %= MOD
                n -= v
        return ans