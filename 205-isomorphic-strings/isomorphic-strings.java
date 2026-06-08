class Solution {
    public boolean isIsomorphic(String s, String t) {

        int[] mappingsS = new int[256];
        int[] mappingsT = new int[256];


        for(int i = 0; i < s.length(); i++){
            int a = s.charAt(i);
            int b = t.charAt(i);


            if(mappingsS[a] != 0 && mappingsS[a] != b) return false;
            if(mappingsT[b] != 0 && mappingsT[b] != a) return false;
            

            mappingsS[a] = b;
            mappingsT[b] = a;

        }

        return true;
    }
}