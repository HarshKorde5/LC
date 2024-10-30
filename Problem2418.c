/*
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** sortPeople(char ** names, int namesSize, int* heights, int heightsSize, int* returnSize)
{
int temp;
char *str;
*returnSize=namesSize;
for(int i=0;i<namesSize;i++)
{
  for(int j=i+1;j<namesSize;j++){
    if(heights[i]<heights[j])
    { 
      temp=heights[i];
      heights[i]=heights[j];
      heights[j]=temp;
      str=names[i];
      names[i]=names[j];
      names[j]=str;
    }
  }
}
return names;
}

int main()
{
    return 0;
}