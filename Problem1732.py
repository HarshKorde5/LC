"""
Docstring for Problem1732
There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

"""

from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        top = 0
        curr = 0

        for g in gain:
            curr += g
            top = max(top,curr)
            
        return top
    
    
def main():
    sol = Solution()
    gain = [-4,-3,-2,-1,4,3,2]
    
    print(f"Largest altitude achieved is : {sol.largestAltitude(gain)}")
    
    
if __name__ == "__main__":
    main()