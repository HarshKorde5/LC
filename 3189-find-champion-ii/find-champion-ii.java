class Solution {
    public int findChampion_01(int n, int[][] edges) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            set.add(i);
        }

        for (int[] e : edges) {
            set.remove(e[1]);
        }

        if (set.size() == 1) {
            return set.iterator().next();
        }

        return -1;
    }

    public int findChampion(int n, int[][] edges) {
        int[] indegree = new int[n];

        for (int[] edge : edges) {
            indegree[edge[1]]++;
        }

        int champ = -1;
        int champCount = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                champCount++;
                champ = i;
            }
        }

        return champCount > 1 ? -1 : champ;
    }
}