"""
You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any index i from the array and flip all the elements from index i to the end of the array.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1.
"""
def minOperations(nums):
    res = 0
    flipState = 0
    for x in nums:
        if x == flipState:
            flipState = 1 - flipState
            res += 1

    return res


def main():
    nums = [1,0,1,0,0,0,1]
    print("Minimum operations needed are : ",minOperations(nums))


if __name__ == "__main__":
    main()
