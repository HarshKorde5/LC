public class Solution {
    private boolean[] visited;
    private List<List<Integer>> res;

    public List<List<Integer>> permuteUnique(int[] nums) {
        res = new ArrayList<>();
        visited = new boolean[nums.length];
        Arrays.sort(nums);
        List<Integer> perm = new ArrayList<>();
        dfs(nums, perm);
        return res;
    }

    private void dfs(int[] nums, List<Integer> perm) {
        if (perm.size() == nums.length) {
            res.add(new ArrayList<>(perm));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
                continue;

            visited[i] = true;
            perm.add(nums[i]);
            dfs(nums, perm);
            visited[i] = false;
            perm.remove(perm.size() - 1);
        }
    }
}