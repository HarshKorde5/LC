class Solution {
    private boolean checkIfPossible(int[] piles, int rate, int hours){
        for(int bananas : piles){

            hours -= bananas / rate;

            if(bananas % rate > 0) hours -= 1;
        }
        return hours >= 0 ? true : false;
    }

    public int minEatingSpeed(int[] piles, int h) {
        Arrays.sort(piles);
        int n = piles.length;
        int max = Arrays.stream(piles).max().getAsInt();

        int start = 1, end = max, res = -1;

        while(start <= end){
            int rate = (start + end) / 2;

            if(checkIfPossible(piles, rate,h)){
                res = rate;
                end = rate - 1;
            }else{
                start = rate + 1;
            }
        }

        return res;
    }
}
