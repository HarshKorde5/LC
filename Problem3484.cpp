/*
A spreadsheet is a grid with 26 columns (labeled from 'A' to 'Z') and a given number of rows. Each cell in the spreadsheet can hold an integer value between 0 and 105.

Implement the Spreadsheet class:

Spreadsheet(int rows) Initializes a spreadsheet with 26 columns (labeled 'A' to 'Z') and the specified number of rows. All cells are initially set to 0.
void setCell(String cell, int value) Sets the value of the specified cell. The cell reference is provided in the format "AX" (e.g., "A1", "B10"), where the letter represents the column (from 'A' to 'Z') and the number represents a 1-indexed row.
void resetCell(String cell) Resets the specified cell to 0.
int getValue(String formula) Evaluates a formula of the form "=X+Y", where X and Y are either cell references or non-negative integers, and returns the computed sum.
Note: If getValue references a cell that has not been explicitly set using setCell, its value is considered 0.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Spreadsheet {
    private:
        vector<vector<int>> cells;

    public:
        Spreadsheet(int rows) {
            cells = vector<vector<int>>(rows, vector<int>(26,0));
        }
        
        void setCell(string cell, int value) {
            int col = cell[0] - 'A';
            int row = stoi(cell.substr(1)) - 1;
            cells[row][col] = value;
        }
        
        void resetCell(string cell) {
            setCell(cell,0);
        }
        
        int getValue(string formula) {
            int idx = formula.find('+');
            string left = formula.substr(1,idx - 1);
            string right = formula.substr(idx+1);

            int leftVal = 
                isalpha(left[0]) 
                ? cells[stoi(left.substr(1))-1][left[0]-'A'] 
                : stoi(left);
            
            int rightVal = 
                isalpha(right[0])
                ? cells[stoi(right.substr(1)) - 1][right[0]- 'A']
                :stoi(right);


            return leftVal + rightVal;
        }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

 int main(){
    Spreadsheet* obj = new Spreadsheet(10);
    obj->setCell("A10",101);
    obj->resetCell("A10");
    int param_3 = obj->getValue("=10+A10");

    return 0;
 }