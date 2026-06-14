class Solution {
    public String reverseWords_01(String s) {
        String res = new String();
        int n = s.length();
        int i = 0;

        while(i < n){
            
            while(i < n && s.charAt(i) == ' '){
                i++;
            }
            if(i == n) break;
            StringBuilder temp = new StringBuilder();

            while(i < n && s.charAt(i) != ' '){
                temp.append(s.charAt(i));
                i++;
            }

            if(res.isEmpty()){
                res = temp.toString();
            }else{
                res = temp.toString() + ' ' + res;
            }

        }

        return res;
    }

    public String reverseWords(String s) {
        String[] words = s.split("\\s+");
        StringBuilder res = new StringBuilder();

        for (int i = words.length - 1; i >= 0; i--) {
            res.append(words[i]);
            if (i != 0) {
                res.append(" ");
            }
        }

        return res.toString().trim();
    }
}


