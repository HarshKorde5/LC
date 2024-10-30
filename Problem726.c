/*
Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.

*/



#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct Element_info
{
    char name[3];
    int count;
};

int cmp(const void *a,const void *b)
{
    return strcmp(((struct Element_info *)a)->name, ((struct Element_info*)b)->name);
}

char* countOfAtoms(char* formula)
{
    int len = strlen(formula);
    int i = 0;

    struct Element_info Element[len];
    int ele_count = 0;

    int Stack[len];
    int top = -1;

    while(i < len)
    {
        if(isupper(formula[i]))
        {
            //Read element
            int j = 0;
            Element[ele_count].name[j++] = formula[i++];
            if(i < len && islower(formula[i]))
            {
                Element[ele_count].name[j++] = formula[i++];
            }
            Element[ele_count].name[j] = '\0';

            //read count
            int num = 0;
            while(i < len && isdigit(formula[i]))
            {
                num = num*10+(formula[i++]-'0');
            }
            if(num == 0)
            {
                num = 1;
            }
            Element[ele_count].count += num;
            ele_count++;
        }
        else if(formula[i] == '(')
        {
            //Push current count to stack;

            Stack[++top] = ele_count;
            i++;
        }
        else if(formula[i] == ')')
        {
            //Pop count from stack
            int prev_count = Stack[top--];
            int multiplier = 0;
            i++;
            while(i < len && isdigit(formula[i]))
            {
                multiplier = multiplier * 10 + (formula[i] - '0');
            }
            if(multiplier == 0)
            {
                multiplier = 1;
            }

            for(int j = prev_count;j < ele_count;j++)
            {
                Element[j].count *= multiplier;
            }
        }
    }

    for(i = 0;i < ele_count;i++)
    {
        for(int j = i + 1;j < ele_count;j++)
        {
            if(strcmp(Element[i].name,Element[j].name) == 0)
            {
                Element[i].count += Element[j].count;
                for(int k = j; k < ele_count - 1;k++)
                {
                    Element[k] = Element[k + 1];
                }
                ele_count--;
                j--;
            }
        }
    }

    qsort(Element,ele_count,sizeof(struct Element_info),cmp);

    char *ret = (char*)malloc(len*sizeof(char));
    ret[0] = '\0';

    for(i = 0;i < ele_count;i++)
    {
        strcat(ret,Element[i].name);
        if(Element[i].count > 1)
        {
            char count_str[10];
            sprintf(count_str,"%d",Element[i].count);
            strcat(ret, count_str);
        }
    }

    return ret;
}

int main()
{
    char formula[] = {"H2O"};

    char ret[] = countOfAtoms(formula);

    printf("Answer : %s\n",ret);

    return 0;
}