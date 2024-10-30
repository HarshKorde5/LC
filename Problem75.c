/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

*/

void sortColors(int* nums, int numsSize)
{
    int low = 0;
    int high = numsSize - 1;
    int i = 0,temp = 0;

    while(i <= high)
    {
        if(nums[i] == 0)
        {
            temp = nums[low];
            nums[low] = nums[i];
            nums[i] = temp;
            low++;
        }

        if(nums[i] == 2)
        {
            temp = nums[high];
            nums[high] = nums[i];
            nums[i] = temp;
            high--;
            continue;
        }

        i++;
    }
}


int main()
{


    int arr[] = {2,0,2,1,1,0};
    sortColors(arr,6);

    return 0;
}