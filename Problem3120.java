/*
3120. Count the Number of Special Characters I

You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.
*/

import java.util.HashSet;

class Solution {
    public int numberOfSpecialChars(String word) {
        boolean lower[] = new boolean[26];
        boolean upper[] = new boolean[26];

        for(char ch : word.toCharArray()){
            if(Character.isLowerCase(ch)){
                lower[ch - 'a'] = true;
            }else{
                upper[ch - 'A'] = true;
            }
        }

        int res = 0;

        for(int i = 0; i < 26; i++){
            if(lower[i] & upper[i]){
                res++;
            }
        }

        return res;
    }

    public int numberOfSpecialChars_01(String word) {
        HashSet<Character> set = new HashSet<>();
        for(char ch : word.toCharArray()){
            set.add(ch);
        }

        int res = 0;

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(set.contains(ch) && set.contains((char)(ch - 'a' + 'A'))){
                res++;
            }
        }

        return res;
    }
}

class Problem3120{
  public static void main(String[] args){
    Solution sobj = new Solution();
    
    String str = "aaAAbBajdiI";
    
    int count = sobj.numberOfSpecialChars(str);
    System.out.println("Number of special characters in the string : "+str+" are : "+count);
    
  }
} 
