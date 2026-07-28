public class Solution {
    public List<Integer> majorityElement_brute(int[] nums) {
        Set<Integer> res = new HashSet<>();
        for (int num : nums) {
            int count = 0;
            for (int i : nums) {
                if (i == num) count++;
            }
            if (count > nums.length / 3) {
                res.add(num);
            }
        }
        return new ArrayList<>(res);
    }

    public List<Integer> majorityElement(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        List<Integer> res = new ArrayList<>();
        for (int key : count.keySet()) {
            if (count.get(key) > nums.length / 3) {
                res.add(key);
            }
        }

        return res;
    }
}