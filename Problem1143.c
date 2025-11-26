/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char *longestCommonSubsequence(char *a, char *b)
{
    int m = strlen(a);
    int n = strlen(b);

    // Allocate DP table
    int mat[m + 1][n + 1];

    // Initialize
    for (int i = 0; i <= m; i++)
        mat[i][0] = 0;
    for (int j = 0; j <= n; j++)
        mat[0][j] = 0;

    // Fill table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                mat[i][j] = 1 + mat[i - 1][j - 1];
            }
            else
            {
                mat[i][j] = (mat[i - 1][j] > mat[i][j - 1])
                                ? mat[i - 1][j]
                                : mat[i][j - 1];
            }
        }
    }

    // Allocate LCS string
    int len = mat[m][n];
    char *lcs = malloc(len + 1);
    lcs[len] = '\0';

    // Reconstruct the LCS by tracing backwards
    int i = m, j = n, k = len - 1;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs[k--] = a[i - 1];
            i--;
            j--;
        }
        else
        {
            if (mat[i - 1][j] > mat[i][j - 1])
                i--;
            else
                j--;
        }
    }

    return lcs;
}



int longestCommonSubsequence_recurrsive_tle(char* a, char* b) {
    int lcs(char* a, char* b, int i, int j) {

        if (a[i] == '\0' || b[j] == '\0') {
            return 0;
        } else if (a[i] == b[j]) {
            return 1 + lcs(a, b, i + 1, j + 1);
        } else {
            return fmax(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));
        }
    }
    return lcs(a, b, 0, 0);
}

int main()
{
    char a[] = "abcde";
    char b[] = "ace";

    int ret = longestCommonSubsequence_recurrsive_tle(a, b);
    printf("Using recurrsion : %d\n",ret);
    
    char *result = longestCommonSubsequence(a, b);
    printf("Longest Common Subsequence from \"%s\" and \"%s\" is \"%s\"\n", a, b, result);

    free(result);
    return 0;
}
