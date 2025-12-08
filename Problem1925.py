"""
Docstring for Problem1925
A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
"""

from math import sqrt

class Solution:
    def countTriples(self, n: int) -> int:
        res = 0
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                c = int(sqrt(a*a + b*b))
                if c <= n and c*c == a*a + b*b:
                    res += 1
        
        return res
    
    
    
if __name__ == "__main__":
    sobj = Solution()
    n = 5
    ret = sobj.countTriples(n)
    print(f"Total triples for n = {n} are : {ret}")