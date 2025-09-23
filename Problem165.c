/*
Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
*/

#include<stdio.h>
#include<string.h>

int compareVersion(char* version1, char* version2) {
    const int n1 = strlen(version1), n2 = strlen(version2);

    int x1 = 0, x2 = 0;

    for(int i = 0, j = 0; i < n1 || j < n2; i++, j++){
        while( i < n1 && version1[i] != '.'){
            x1 = 10 * x1 + (version1[i] - '0');
            i++;
        }

        while(j < n2 && version2[j] != '.'){
            x2 = 10 * x2 + (version2[j] - '0');
            j++;            
        }

        if(x1 < x2) return -1;
        else if(x1 > x2) return 1;

        x1 = 0;
        x2 = 0;
    }

    return 0;
}

int main(){

     char version1[100], version2[100];

    printf("Enter first version: ");
    scanf("%99s", version1);

    printf("Enter second version: ");
    scanf("%99s", version2);

    int result = compareVersion(version1, version2);

    if(result == 0)
        printf("Versions are equal.\n");
    else if(result < 0)
        printf("Version \"%s\" is smaller than \"%s\".\n", version1, version2);
    else
        printf("Version \"%s\" is greater than \"%s\".\n", version1, version2);

    return 0;
}