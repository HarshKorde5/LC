#include<iostream>

class Solution {
    public:
        long long coloredCells1(int n) {
            long long numBlueCells = 1;
            int addend = 4;
            while (--n) {
                numBlueCells += addend;
                addend += 4;
            }
            return numBlueCells;
        }
    
        long long coloredCells(int n) { return 1 + (long long)n * (n - 1) * 2; }
};

int main(){
    Solution s;
    std::cout<<s.coloredCells(4);

    return 0;
}
