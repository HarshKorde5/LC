import java.util.*;

class Solution {
        public int[] nextGreaterElement1(int[] findNums, int[] nums) {
        Map<Integer, Integer> map = new HashMap<>(); // map from x to next greater element of x
        Stack<Integer> stack = new Stack<>();
        for (int num : nums) {
            while (!stack.isEmpty() && stack.peek() < num)
                map.put(stack.pop(), num);
            stack.push(num);
        }   
        for (int i = 0; i < findNums.length; i++)
            findNums[i] = map.getOrDefault(findNums[i], -1);
        return findNums;
    }

    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] indexArray = new int[10001]; 
        for (int i = 0; i < nums2.length; i++) {
            indexArray[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.length; i++) {
            nums1[i] = findNextGreater(nums2, indexArray[nums1[i]]);
        }
        return nums1;
    }
    public int findNextGreater(int[] nums2, int index) {
        for (int i = index + 1; i < nums2.length; i++) {
            if (nums2[i] > nums2[index]) return nums2[i];
        }
        return -1; 
    }
}

class Problem496{
    public static void main(String arg[]){

        Solution s = new Solution();

        int[] nums1 = {4,1,2};
        int[] nums2 = {1,3,4,2};
        int[] ret = s.nextGreaterElement(nums1,nums2);

    }
}