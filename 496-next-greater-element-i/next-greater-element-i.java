public class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> nums1Idx = new HashMap<>();
        for (int i = 0; i < nums1.length; i++) {
            nums1Idx.put(nums1[i], i);
        }

        int[] res = new int[nums1.length];
        Arrays.fill(res, -1);

        for (int i = 0; i < nums2.length; i++) {
            if (!nums1Idx.containsKey(nums2[i])) {
                continue;
            }
            for (int j = i + 1; j < nums2.length; j++) {
                if (nums2[j] > nums2[i]) {
                    int idx = nums1Idx.get(nums2[i]);
                    res[idx] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
}