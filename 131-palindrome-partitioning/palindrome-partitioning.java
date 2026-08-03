class Solution {
    List<List<String>> res;
    List<String> part;
    public List<List<String>> partition(String s) {
        res = new ArrayList<>();
        part = new ArrayList<>();

        dfs(s,0);
        return res;
    }

    private void dfs(String s, int i){
        if(i >= s.length()){
            res.add(new ArrayList<>(part));
            return;
        }

        for(int j = i; j < s.length(); j++){
            if(isPalindrome(s, i, j)){
                part.add(s.substring(i, j+1));
                dfs(s, j + 1);
                part.removeLast();
            }
        }
    }

    private boolean isPalindrome(String s, int l, int r){
        while(l < r){
            if(s.charAt(l) != s.charAt(r)){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
}
