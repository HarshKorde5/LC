/*
Find Most Frequent Vowel and Consonant
You are given a string s consisting of lowercase English letters ('a' to 'z').
Your task is to:
Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
Find the consonant (all other letters excluding vowels) with the maximum frequency.
Return the sum of the two frequencies.

Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.

The frequency of a letter x is the number of times it occurs in the string.

*/


#include<stdio.h>

int maxFreqSum(char* s) {


    char freq[26] = {0};

    while(*s != '\0'){

        freq[*s - 'a']++;
        s++;
    }


    int maxVowel = 0, maxConsonant = 0;
    char v = '\0', c = '\0';
    for(int i = 0;i < 26; i++){

        char ch = i + 'a';

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            if( freq[i] > maxVowel){
                maxVowel = freq[i];
                v = ch;
            }
        }else if(freq[i] > maxConsonant){
            maxConsonant = freq[i];
            c = ch;
        }
    }


    printf("Maximum frequency of vowel '%c' is : %d\n", v,maxVowel);
    printf("Maximum frequency of consonants '%c' is : %d\n", c,maxConsonant);

    return maxVowel + maxConsonant;
}

void toLowerCase(char *str){
    while(*str != '\0'){
        if(*str >= 'A' && *str <= 'Z'){
            *str = *str + 32;
        }
        str++;
    }

}

int main(){

    char str[100];

    printf("Enter your string to check : ");
    scanf("%[^\n]s", str);

    toLowerCase(str);
    printf("Lowercased input string is : %s\n",str);


    int result = 0;
    result = maxFreqSum(str);

    printf("Max Frequency sum of vowels and consonants is : %d\n",result);

    return 0;
}