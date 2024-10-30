/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    int a, b;
    for (int i=triangleSize-2; i > -1; i--){
        for (int j=0; j <= i; j++){
            a = triangle[i+1][j];
            b = triangle[i+1][j+1];
            triangle[i][j] += a < b ? a : b;
        }
    }
    return triangle[0][0];
}

int main()
{
    int triangle[4][4] = {{2,0,0,0},{3,4,0,0},{6,5,7,0},{4,1,8,3}};
    int triangleColSize = 0;
    int ret = minimumTotal(triangle[][4],4,&triangleColSize);

    return 0;
}