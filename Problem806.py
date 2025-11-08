"""
You are given a string s of lowercase English letters and an array widths denoting how many pixels wide each lowercase English letter is. Specifically, widths[0] is the width of 'a', widths[1] is the width of 'b', and so on.

You are trying to write s across several lines, where each line is no longer than 100 pixels. Starting at the beginning of s, write as many letters on the first line such that the total width does not exceed 100 pixels. Then, from where you stopped in s, continue writing as many letters as you can on the second line. Continue this process until you have written all of s.

Return an array result of length 2 where:

result[0] is the total number of lines.
result[1] is the width of the last line in pixels.
"""

from typing import List


class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        
        lines, current_width = 1, 0
        
        for ch in s:
            width = widths[ord(ch) - ord('a')]

            if current_width + width <= 100:
                current_width += width
            else:
                lines += 1
                current_width = width
            
        return [lines, current_width]
    
    
def main():
    widths = [10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10]
    s = "abcdefghijklmnopqrstuvwxyz"

    sol = Solution()
    result = sol.numberOfLines(widths, s)

    print("Number of lines needed:", result[0])
    print("Width used on the last line:", result[1])

if __name__ == "__main__":
    main()
