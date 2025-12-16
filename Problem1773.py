"""
You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == colori.
ruleKey == "name" and ruleValue == namei.
Return the number of items that match the given rule.
"""

from typing import List
class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        count = 0

        idx = 0 if ruleKey == "type" else 1 if ruleKey == "color" else 2
        for item in items:
            if item[idx] == ruleValue:
                count += 1

        return count


def main():
    sol = Solution()
    
    items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]]
    ruleKey = "color"
    ruleValue = "silver"
    print(f"Total matches in the items list is : {sol.countMatches(items,ruleKey,ruleValue)}")
    
    
if __name__ == "__main__":
    main()