"""
On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:

In 1 second, you can either:
move vertically by one unit,
move horizontally by one unit, or
move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
You have to visit the points in the same order as they appear in the array.
You are allowed to pass through points that appear later in the order, but these do not count as visits.
 
"""
from typing import List
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        ans = 0

        for i in range(0, len(points)-1):
            curr_x, curr_y = points[i]
            target_x, target_y = points[i + 1]

            ans += max(abs(target_x - curr_x), abs(target_y - curr_y))

        return ans
    

def main():
    sobj = Solution()
    points = [[1,1],[3,4],[-1,0]]
    ret = sobj.minTimeToVisitAllPoints(points)
    print("Minimum time to visit all points is : ", ret)

if __name__ == "__main__":
    main()