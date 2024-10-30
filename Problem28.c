//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
#include<stdio.h>
#include<string.h>

int strStr(char* haystack, char* needle)
{
    int index = 0;
    int len_needle = strlen(needle);
    int len_haystack = strlen(haystack);


    for(int i = 0,j = 0;i < len_haystack;i++)
    {
        if(haystack[i] == needle[0])
        {
            index = i;
            while(j < len_needle)
            {
                if(haystack[i] != needle[j])
                {
                    i = index;
                    j = 0;
                    break;
                }
                i++;
                j++;
            }
        }
        if(j == len_needle)
        {
            return index;
        }
    }

    return -1;
}

int main()
{

    char str[]= {"Hello World"};

    char str2[] = {"llo"};

    int ret = strStr(str,str2);
    printf("%d",ret);

    return 0;
}