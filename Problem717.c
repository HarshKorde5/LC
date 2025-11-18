#include<stdio.h>
#include<stdbool.h>

bool isOneBitCharacter(int *bits, int bitsSize)
{
    // return (bits[bitsSize - 1] == 0) ? ((bitsSize - 1) % 2 == 0 )? true : false : false;    // fails for [0,0]

    int i = 0;
    while (i < bitsSize - 1)
    {
        if (bits[i] == 0)
        {
            i++;
        }
        else
        {
            i += 2;
        }
    }

    if (i == bitsSize)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main(){
    int bits[] = {1,1,0,1,0,0,1,0,1,1,0};
    int n = 11;
    bool ret = isOneBitCharacter(bits, n);

    if(ret){
        printf("Valid array\n");
    }else{
        printf("Invalid array\n");
    }   
    return 0;
}