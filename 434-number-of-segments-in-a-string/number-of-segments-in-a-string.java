class Solution {
    public int countSegments(String s) {

        int res = 0;
        for(int i = 0; i < s.length();i++){
            if(s.charAt(i) != ' '){
                while(i < s.length() && s.charAt(i) != ' ' ) i++;

                res++;
            }
        }

        return res;
    }
}