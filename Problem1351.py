"""
Docstring for Problem1351

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
"""

from typing import List

class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        r, c, cnt = 0, n - 1, 0

        while r < m and c >= 0:
            if grid[r][c] < 0:
                cnt += m - r
                c -= 1
            else:
                r += 1

        return cnt
    
    
def main():
    sobj = Solution()
    
    grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    
    print(f"Count of negative elements in sorted grid is : {sobj.countNegatives(grid)}")
    
    
    
    
if __name__ == "__main__":
    main()