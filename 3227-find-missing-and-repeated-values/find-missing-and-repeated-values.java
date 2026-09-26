public class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int N = grid.length;
        Set<Integer> seen = new HashSet<>();
        int doubleVal = 0, missing = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (seen.contains(grid[i][j])) {
                    doubleVal = grid[i][j];
                }
                seen.add(grid[i][j]);
            }
        }

        for (int num = 1; num <= N * N; num++) {
            if (!seen.contains(num)) {
                missing = num;
                break;
            }
        }

        return new int[]{doubleVal, missing};
    }
}