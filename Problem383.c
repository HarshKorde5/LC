/*
constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

*/


#include<stdio.h>
#include<bool.h>


bool canConstruct(char* ransomNote, char* magazine) 
{
    int i = 0,j = 0;
    bool flag = true;

    while(ransomNote[i] != '\0')
    {
        j = 0;
        while(magazine[j] != '\0')
        {
            if(magazine[j] == ransomNote[i])
            {
                magazine[j] = '!';
                flag = true;
                break;
            }
            else
            {
                flag = false;
            }
            j++;
        }
        if(flag == false)
        {
            break;
        }
        i++;
    }

    return flag;
}

int main()
{
    char str1[2] = {"aa"};
    char str2[3] = {"aab"};

    printf("%s\n",canConstruct(str1,str2));

    return 0;
}