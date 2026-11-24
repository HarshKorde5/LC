bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int arr[1001] = {0};

    for(int i = 0;i < tripsSize; i++){
        arr[trips[i][1]] += trips[i][0];
        arr[trips[i][2]] -= trips[i][0];
    }

    int res = 0, cnt = 0;

    for(int i = 0; i < 1001; i++){
        cnt += arr[i];
        res = res > cnt ? res : cnt;
    }

    return res <= capacity;
}