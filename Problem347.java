/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap();

        for (int x : nums) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        // List<Integer> list = new ArrayList(mp.keySet());
        // Collections.sort(list, (a, b) -> mp.get(b) - mp.get(a));

        PriorityQueue<Integer> heap = new PriorityQueue<>((a, b) -> mp.get(a) - mp.get(b));

        for (int num : mp.keySet()) {
            heap.offer(num);
            if (heap.size() > k) {
                heap.poll(); // remove least frequent
            }
        }
        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            // res[i] = list.get(i);
            res[i] = heap.poll();

        }

        return res;

    }

    public int[] topKFrequent_02(int[] nums, int k) {

        List<Integer>[] buckets = new List[nums.length + 1];
        Map<Integer, Integer> mp = new HashMap();

        for (int x : nums) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }

        for (int key : mp.keySet()) {
            int freq = mp.get(key);
            if (buckets[freq] == null) {
                buckets[freq] = new ArrayList<>();
            }
            buckets[freq].add(key);
        }

        int[] res = new int[k];
        int idx = 0;

        for (int i = buckets.length - 1; i >= 0 && idx < k; i--) {
            if (buckets[i] != null) {
                for (int x : buckets[i]) {
                    res[idx++] = x;
                    if (idx == k)
                        break;
                }
            }
        }
        return res;
    }

    public int[] topKFrequent_01(int[] nums, int k) {
        if (k == nums.length) {
            return nums;
        }

        Map<Integer, Integer> mp = new HashMap();
        for (int x : nums) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }

        Queue<Integer> q = new PriorityQueue<>((a, b) -> mp.get(a) - mp.get(b));

        for (int x : mp.keySet()) {
            q.add(x);
            if (q.size() > k) {
                q.poll();
            }
        }

        int[] res = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            res[i] = q.poll();
        }

        return res;
    }
}

class Problem347 {
    public static void main(String[] args) {
        int nums[] = { 1, 1, 1, 2, 2, 3 };
        int k = 2;
        Solution sobj = new Solution();
        int ret[] = sobj.topKFrequent(nums, k);

        for (int x : ret) {
            System.out.println(x);
        }
    }
}