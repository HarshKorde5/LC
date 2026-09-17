class Solution {
    public int findChampion(int n, int[][] edges) {
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < n; i++){
            set.add(i);
        }

        for(int[] e : edges){
            set.remove(e[1]);
        }

        if(set.size() == 1){
            return set.iterator().next();
        }

        return -1;
    }
}