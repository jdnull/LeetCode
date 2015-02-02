class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        strList = list(s)
        power = len(strList) - 1
        ret = 0
        for c in strList:
        	c = ord(c)-64
        	ret += c * 26 ** power
        	power -= 1
        return ret
