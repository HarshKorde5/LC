class Solution {
    List<List<Integer>> res;
    public List<List<Integer>> combine(int n, int k) {
        res = new ArrayList<>();

        dfs(n, k, 1, new ArrayList<Integer>());
        return res;
    }

    private void dfs(int n, int k, int currval, List<Integer> comb) {
        if (currval > n) {
            if (comb.size() == k) {
                res.add(new ArrayList<>(comb));
            }
            return;
        }

        comb.add(currval);
        dfs(n, k, currval + 1, comb);
        comb.removeLast();
        dfs(n, k, currval + 1, comb);
    }
}