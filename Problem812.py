'''
Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. 
Answers within 10-5 of the actual answer will be accepted.
'''

class Solution:
    def largestTriangleArea(self, points):
        max_area = 0
        n = len(points)

        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    x1, y1 = points[i]
                    x2, y2 = points[j]
                    x3, y3 = points[k]
                    current_area = abs(0.5 * (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)))
                    max_area = max(max_area, current_area)
                    
        return max_area


def main():
    obj = Solution()

    points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
    print("Area : ",obj.largestTriangleArea(points))

if __name__ == "__main__":
    main()
