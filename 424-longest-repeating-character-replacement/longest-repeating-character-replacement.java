public class Solution {
    public int characterReplacement_01(String s, int k) {
        int res = 0;
        HashSet<Character> charSet = new HashSet<>();
        for (char c : s.toCharArray()) {
            charSet.add(c);
        }

        for (char c : charSet) {
            int count = 0, l = 0;
            for (int r = 0; r < s.length(); r++) {
                if (s.charAt(r) == c) {
                    count++;
                }

                while ((r - l + 1) - count > k) {
                    if (s.charAt(l) == c) {
                        count--;
                    }
                    l++;
                }

                res = Math.max(res, r - l + 1);
            }
        }
        return res;
    }

    public int characterReplacement(String s, int k) {
        int res = 0;
        int n = s.length();

        int start = 0, end = 0;
        Map<Character, Integer> map = new HashMap<>();
        int maxFreq = 0;

        while (end < n) {
            map.put(s.charAt(end), map.getOrDefault(s.charAt(end), 0) + 1);

            maxFreq = Math.max(maxFreq, map.get(s.charAt(end)));

            while ((end - start + 1) - maxFreq > k) {
                map.put(s.charAt(start), map.get(s.charAt(start)) - 1);
                start++;

                for(int val : map.values()){
                    maxFreq = Math.max(maxFreq,val);
                }
            }

            res = Math.max(res, end - start + 1);
            end++;
        }

        return res;
    }
}