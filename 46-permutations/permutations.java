class Solution {
    List<List<Integer>> res;
    public List<List<Integer>> permute(int[] nums) {
        res = new ArrayList<>();
        backtrack(new ArrayList<>(), nums, new boolean[nums.length]);
        return res;
    }


    private void backtrack(List<Integer> perm, int[] nums, boolean[] visited){
        if(perm.size() == nums.length){
            res.add(new ArrayList<>(perm));
            return;
        }


        for(int i = 0;i < visited.length; i++){
            if(!visited[i]){
                perm.add(nums[i]);
                visited[i] = true;

                backtrack(perm, nums, visited);

                perm.removeLast();
                visited[i] = false;
            }
        }

    }
}
