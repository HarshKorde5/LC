class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        int n = s.length();
        int start = 0, end = 0, res = 0;

        while(end < n){

            while(set.contains(s.charAt(end))){
                set.remove(s.charAt(start));
                start++;
            }

            set.add(s.charAt(end));
            res = res > end - start + 1 ? res : end - start + 1;
            end++;
        }

        return res;
    }
}
