/*
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of only uppercase and lowercase English letters (no punctuation).

For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
You are given a sentence s​​​​​​ and an integer k​​​​​​. You want to truncate s​​​​​​ such that it contains only the first k​​​​​​ words. Return s​​​​​​ after truncating it.
*/

#include <stdio.h>

char* truncateSentence(char* s, int k) {
    char* t = s;

    while (k > 0 && *t != '\0') {
        while (*t != '\0' && *t != ' ') {
            t++;
        }
        k--;

        if (*t == ' ') {
            t++;
        }
    }

    if (k == 0 && *(t - 1) == ' ') {
        *(t - 1) = '\0';
    } else {
        *t = '\0';
    }

    return s;
}

int main() {
    char s1[] = "Hello how are you";
    int k1 = 2;
    printf("Result: \"%s\"\n", truncateSentence(s1, k1));

    char s2[] = "OneWord";
    int k2 = 1;
    printf("Result: \"%s\"\n", truncateSentence(s2, k2));

    char s3[] = "This is a simple test case";
    int k3 = 4;
    printf("Result: \"%s\"\n", truncateSentence(s3, k3));

    char s4[] = "C programming is fun";
    int k4 = 3;
    printf("Result: \"%s\"\n", truncateSentence(s4, k4));

    return 0;
}


