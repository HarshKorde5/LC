class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int n = speed.length;
        double[][] pairs = new double[n][2];

        for(int i = 0;i < n; i++){
            pairs[i][0] = position[i];
            pairs[i][1] = (double)(target - position[i] )/ speed[i];
        }

        Arrays.sort(pairs, (a,b) -> Double.compare(a[0],b[0]));
        int fleets = 0;
        double maxTime = 0;

        for(int i = n - 1; i >= 0; i--){
            double currTime = pairs[i][1];

            if(currTime > maxTime){
                fleets++;
                maxTime = currTime;
            }
        }

        return fleets;
    }
}
