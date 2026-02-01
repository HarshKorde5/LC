/*

*/
#include <stdio.h>

int minimumCost(int *nums, int numsSize)
{
    int a = 100;
    int b = 100;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] < a)
        {
            b = a;
            a = nums[i];
        }
        else if (nums[i] < b)
        {
            b = nums[i];
        }
    }

    return nums[0] + a + b;
}

int main()
{
    int nums[] = {10, 3, 1, 1};
    int ret = minimumCost(nums, 4);
    printf("Minimum cost is : %d\n", ret);
    return 0;
}