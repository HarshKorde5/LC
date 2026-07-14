class Solution {
    public int pivotInteger1(int n) {
        int sum = n * (n + 1) / 2;

        int currsum = 0;

        for (int i = 1; i <= n; i++) {
            currsum += i;

            if (currsum == (sum - currsum + i)) {
                return i;
            }
        }

        return -1;
    }

    public int pivotInteger(int n) {
        int leftValue = 1;
        int rightValue = n;
        int sumLeft = leftValue;
        int sumRight = rightValue;

        if (n == 1)
            return n;

        while (leftValue < rightValue) {
            if (sumLeft < sumRight) {
                sumLeft += ++leftValue;
            } else {
                sumRight += --rightValue;
            }

            if (sumLeft == sumRight && leftValue + 1 == rightValue - 1) {
                return leftValue + 1;
            }
        }

        return -1;
    }
}