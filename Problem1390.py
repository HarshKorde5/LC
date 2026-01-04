from math import floor, sqrt
def sumFourDivisors(nums):
    res = 0

    for num in nums:
        divisor = set()
        for i in range(1, floor(sqrt(num) + 1)):
            if num % i == 0:
                divisor.add(num // i)
                divisor.add(i)
            if len(divisor) > 4:
                break

        if len(divisor) == 4:
            res += sum(divisor)
    return res

def main():
    nums = [21,4,7]
    ret = sumFourDivisors(nums)
    print("Sum of four divisors is : ",ret)
    
if __name__ == "__main__":
    main()
