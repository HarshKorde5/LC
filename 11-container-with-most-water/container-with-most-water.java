class Solution {
    public int maxArea(int[] heights) {
        int res = 0;

        int start = 0, end = heights.length - 1;
        while (start < end) {
            int h = Math.min(heights[start], heights[end]);

            int w = end - start;

            res = Math.max(h * w, res);

            if (h == heights[start]) {
                start++;
            } else {
                end--;
            }
        }

        return res;
    }
}
