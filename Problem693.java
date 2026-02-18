class Solution {
    public boolean hasAlternatingBits(int n) {
        int cur = n % 2;
        n /= 2;
        while (n > 0) {
            if (cur == n % 2) return false;
            cur = n % 2;
            n /= 2;
        }
        return true;
    }
}

class Problem693{
    public static void main(String[] args){
        Solution sobj = new Solution();


        boolean ret = sobj.hasAlternatingBits(10);

        System.out.println(ret);
    }
}