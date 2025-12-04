/*
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.
*/
#include<stdio.h>

int* replaceElements(int* a, int n, int* r) {

    int prev = -1, curr = 0;
    
    for(int i = n - 1; i >= 0; i--){
        curr = a[i];
        a[i] = prev;
        prev = prev > curr ? prev : curr;
    }
    *r = n;
    return a;
}


int main(){
    int a[] = {17, 18, 4, 5, 6, 1};
    int r = 0;
    int n = 6;

    int *ret = replaceElements(a, n, &r);

    printf("Array after replacing elements : \n");
    for(int i = 0; i < n; i++){
        printf("%d\n", ret[i]);
    }

    return 0;

}