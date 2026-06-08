int strStr(char* haystack, char* needle) {
    int m = strlen(haystack);
    int n = strlen(needle);

    if(m == 0) return 0;

    for(int i = 0; i <= m - n; i++){
        if(haystack[i] == needle[0]){
            int j = 1;            
            while(j < n && needle[j] == haystack[i + j]){
                j++;
            }
            if(j == n) return i;
        }
    }

    return -1;
}