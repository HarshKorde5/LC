"""
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

"""

from typing import List

class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        ans = 0

        for i in range(n):
            ans += mat[i][i]
            ans += mat[n-1-i][i]


        if n%2 != 0:
            ans -= mat[n // 2][n // 2]

        return ans

def main():
    sol = Solution()
    mat = [[1,2,3],[4,5,6],[7,8,9]]
    
    print(f"Sum of diagonal elements is : {sol.diagonalSum(mat)}")
    
if __name__ == "__main__":
    main()