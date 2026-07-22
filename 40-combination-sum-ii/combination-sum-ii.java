class Solution {
    private List<List<Integer>> res;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        res = new ArrayList<>();
        Arrays.sort(candidates);
        dfs(candidates, target, 0, new ArrayList<>(), 0);
        return res;
    }

    private void dfs(int[] candidates, int target, int idx, List<Integer> curr, int total){
        if(total == target){
            res.add(new ArrayList<>(curr));
            return;
        }

        if(total > target || idx == candidates.length){
            return;
        }

        curr.add(candidates[idx]);
        dfs(candidates,target, idx + 1, curr, total + candidates[idx]);

        curr.removeLast();

        while(idx + 1 < candidates.length && candidates[idx] == candidates[idx + 1]){
            idx++;
        }

        dfs(candidates, target, idx + 1, curr, total);
    }
}
