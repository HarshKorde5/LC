/*
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space
*/

#include<stdio.h>


/*
int compare(const void*a,const void*b)
{
    return ((*(int*)a) - (*(int*)b));
}

int maximumGap(int* nums, int numsSize)
{
    if(numsSize < 2)
    {
        return 0;
    }

    qsort(nums,numsSize,sizeof(int),compare);

    int diff = 0,max = 0;
    
    for(int i = 1;i < numsSize;i++)
    {
        diff = nums[i] - nums[i - 1];

        if(diff > max)
        {
            max = diff;
        }
    }

    return max;
}
*/


struct Bucket {
    int min_val;
    int max_val;
    int used;
};

// Function to find the maximum difference between successive elements
int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) {
        return 0;
    }
    
    // Step 1: Find the minimum and maximum values in nums
    int min_val = INT_MAX, max_val = INT_MIN;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }
    
    // Step 2: Perform bucket sort on nums
    int bucket_size = (max_val - min_val) / (numsSize - 1);
    if (bucket_size <= 0) {
        bucket_size = 1;
    }
    
    int num_buckets = (max_val - min_val) / bucket_size + 1;
    struct Bucket* buckets = (struct Bucket*)malloc(num_buckets * sizeof(struct Bucket));
    
    // Initialize buckets
    for (int i = 0; i < num_buckets; ++i) {
        buckets[i].min_val = INT_MAX;
        buckets[i].max_val = INT_MIN;
        buckets[i].used = 0;
    }
    
    // Assign numbers into buckets
    for (int i = 0; i < numsSize; ++i) {
        int bucket_index = (nums[i] - min_val) / bucket_size;
        
        if (bucket_index < 0) {
            bucket_index = 0;
        }
        if (bucket_index >= num_buckets) {
            bucket_index = num_buckets - 1;
        }
        
        if (!buckets[bucket_index].used) {
            buckets[bucket_index].min_val = nums[i];
            buckets[bucket_index].max_val = nums[i];
            buckets[bucket_index].used = 1;
        } else {
            if (nums[i] < buckets[bucket_index].min_val) {
                buckets[bucket_index].min_val = nums[i];
            }
            if (nums[i] > buckets[bucket_index].max_val) {
                buckets[bucket_index].max_val = nums[i];
            }
        }
    }
    
    // Step 3: Calculate maximum difference between successive elements
    int max_diff = 0;
    int previous_max = min_val;
    
    for (int i = 0; i < num_buckets; ++i) {
        if (buckets[i].used) {
            max_diff = buckets[i].min_val - previous_max > max_diff ? buckets[i].min_val - previous_max : max_diff;
            previous_max = buckets[i].max_val;
        }
    }
    
    free(buckets);
    
    return max_diff;
}


int main()
{


    return 0;
}