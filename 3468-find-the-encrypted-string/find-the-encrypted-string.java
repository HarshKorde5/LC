class Solution {
    public String getEncryptedString(String s, int k) {
        int n = s.length();
        StringBuilder res = new StringBuilder();

        for(int i = 0; i < n; i++){
            res.append(s.charAt((i+k)%n));
        }

        return res.toString();
    }
}