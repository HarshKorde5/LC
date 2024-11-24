/*
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.


*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        int negativeCount = 0;
        int minAbs = INT_MAX;

        long long sum = 0;

        for(const auto& row : matrix)
        {
            for(auto val : row)
            {

                sum += abs(val);


                if(val < 0)
                {
                    negativeCount++;
                }

                minAbs = min(minAbs,abs(val));
            }
        }


        if(negativeCount % 2 != 0)
        {
            sum -= 2*minAbs;            
            //multiply by 2 because we firstly added the sum of all elements so the one we have to
            //remove is added twice due to flipping of the sign(abs) i.e. if we had -3 as minimum 
            //we added +3 in sum and the diff in -3 and +3 is of 6 so its 2 times 3
        }

        return sum;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> matrix = {{1,-1},{-1,1}};


    cout<<s.maxMatrixSum(matrix);
}