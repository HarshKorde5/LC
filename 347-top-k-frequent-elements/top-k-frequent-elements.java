class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<>();

        for(int x : nums){
            map.put(x, map.getOrDefault(x, 0) + 1);
        }

        List<Map.Entry<Integer, Integer>> entries = new ArrayList<>(map.entrySet());

        entries.sort(
            (a,b) -> Integer.compare(b.getValue(), a.getValue())
        );

        int[] res = new int[k];
        for(int i = 0; i < k; i++){
            res[i] = entries.get(i).getKey();
        }

        return res;
    }
}