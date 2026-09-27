class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        if(s.length() > 12) return res;

        backtrack(0,0,"",s,res);
        return res;
    }

    private void backtrack(int i, int dots, String currIP, String s, List<String> res){
        if(dots == 4 && i == s.length()){
            res.add(currIP.substring(0,currIP.length() - 1));
            return;
        }
        if(dots > 4)    return;

        for(int j = i; j < Math.min(i + 3, s.length()); j++){
            if(i != j && s.charAt(i) == '0')    continue;
            if(Integer.parseInt(s.substring(i,j+1)) < 256){
                backtrack(j+1, dots+1, currIP + s.substring(i,j+1) + ".", s, res);
            }
        }
    }
}