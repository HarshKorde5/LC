/*
Maximum Number of Words You Can Type

There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, 
return the number of words in text you can fully type using this keyboard.
*/

#include<stdio.h>
#include<stdbool.h>

bool contains(char ch, char* brokenLetters){
    while(*brokenLetters != '\0'){
        // printf("Broken letter : %c \t Character : %c\n",*brokenLetters, ch);
        if(ch == *brokenLetters){
            return true;        //found ch is one of our brokenLetters of keyboard
        }
        brokenLetters++;
    }
    return false;
}

// O(n*m)
int canBeTypedWords(char * text, char * brokenLetters){
    printf("\nYour text is : %s",text);
    printf("\nBroken letters are : %s\n",brokenLetters);

    int count = 0;

    char *ptr = text;

    bool flag = true;

    while(*ptr != '\0'){
        // printf("%c\n",*ptr);

        // one word complete
        if(*ptr == ' '){
            // if word is not broken increment the count
            if(flag){
                count++;
            }
            flag = true;        //reset the flag for next word
        }else{
            //check if *ptr is in brokenLetters - contains()
            if(flag && contains(*ptr, brokenLetters)){
                flag = false;
            }
        }

        ptr++;
    }


    return flag ? ++count : count;
}


// O(N + M) : Optimal solution
int canBeTypedWords(char *text, char * brokenLetters){
    int check[26] = {0};

    while(*brokenLetters != '\0'){
        check[*brokenLetters - 'a'] = 1;
        brokenLetters++;
    }

    int count = 0;
    bool flag = true;


    while(*text != '\0'){
        if(*text == ' '){
            if(flag){
                count++;
            }
            flag = true;
        }else{
            if(flag && check[*text - 'a']){
                flag = false;
            }
        }
        text++;
    }

    return flag ? count : ++count;
}

int main(){
    char text[100];
    char brokenLetters[50];

    printf("\nEnter the text : ");
    scanf(" %[^\n]s",text);
    
    printf("\nEnter the broken letters (without space) : ");
    scanf(" %[^\n]s",brokenLetters);

    int result = canBeTypedWords(text, brokenLetters);
    printf("\nCount of words which can be typed : %d\n",result);
    return 0;
}
