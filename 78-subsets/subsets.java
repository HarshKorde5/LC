class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        List<Integer> currsubset = new ArrayList<>();

        rec(nums,0,currsubset,result);
        return result;
    }

    private void rec(int[] nums, int idx, List<Integer> currsubset, List<List<Integer>> result){
        if(idx >= nums.length){
            result.add(new ArrayList<>(currsubset));
            return;
        }


        currsubset.add(nums[idx]);
        rec(nums, idx + 1, currsubset, result);

        currsubset.remove(currsubset.size() - 1);
        rec(nums, idx + 1, currsubset, result);

    }
}
