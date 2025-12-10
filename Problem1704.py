"""
Docstring for Problem1704
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.
"""

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = set('aeiouAEIOU')
        a = b = 0
        i, j = 0, len(s) - 1

        while i < j:
            a += s[i] in vowels
            b += s[j] in vowels
            i += 1
            j -= 1

        return a == b
    
    
def main():
    
    sol = Solution()
    s = "textbook"
    print(f"{s} halves are alike ? : {sol.halvesAreAlike(s)}")
    
if __name__ == "__main__":
    main()