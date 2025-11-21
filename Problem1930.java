/*
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
*/

import java.util.Arrays;

class Solution {
    public int countPalindromicSubsequence(String s) {
        int first[] = new int[26];
        int last[] = new int[26];
        int result = 0;

        Arrays.fill(first, Integer.MAX_VALUE);

        for(int i = 0; i < s.length(); i++){
            first[s.charAt(i) - 'a'] = Math.min(first[s.charAt(i) - 'a'], i);
            last[s.charAt(i) - 'a'] = i;
        }

        for(int i = 0;i < 26; i++){
            if(first[i] < last[i]){
                
                boolean seen[] = new boolean[26];
                int count = 0;

                for(int j = first[i] + 1; j < last[i]; j++){

                    int idx = s.charAt(j) - 'a';
                    if(!seen[idx]){
                        count++;
                        seen[idx] = true;
                    }
                }

                result += count;
            }
        }

        return result;
    }
}


class Problem1930{
    public static void main(String[] args){ 
        Solution sobj = new Solution();

        String str = "bbcbaba";

        int ret = sobj.countPalindromicSubsequence(str);

        System.out.println("Total palindromic subsequences in \""+str+"\" of length 3 are : "+ret);
        
    }
}