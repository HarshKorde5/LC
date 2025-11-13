"""
You are given a binary string s.

You can perform the following operation on the string any number of times:

Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
Move the character s[i] to the right until it reaches the end of the string or another '1'. For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
Return the maximum number of operations that you can perform.

"""
class Solution:
    def maxOperations(self, s: str) -> int:
        ones = 0
        res = 0
        for i, c in enumerate(s):
            if c == '1':
                ones += 1
            elif i > 0 and s[i - 1] == '1':
                res += ones
        return res
    
    
def main():
    
    sol = Solution()
    s = "10011011000"
    print(f"Minimum operations required to shift all 1's in \"{s}\" to the end are : {sol.maxOperations(s)}")
    
if __name__ == "__main__":
    main()