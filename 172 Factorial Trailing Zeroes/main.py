class Solution:
    # @return an integer
    def trailingZeroes(self, n):
        ret = 0
        while n > 0:
        	n /= 5
            ret += n
        return ret