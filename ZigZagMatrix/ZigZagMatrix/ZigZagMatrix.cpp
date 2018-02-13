#include <iostream>
using namespace std;


// Write the code that will take a string and make this conversion given a number of rows:
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

// https://leetcode.com/problems/zigzag-conversion/description/
// https://www.geeksforgeeks.org/print-concatenation-of-zig-zag-string-form-in-n-rows/
class Solution {
public:
    string convert(string s, int numRows) {

        int len = s.length();

        if (len <= numRows || numRows == 1){
            return s;
        }
        else {
            string* sz = new string[numRows];
            bool down; // whether moving down the zig-zag
            int row = 0;

            for (int i = 0; i < len; ++i){
                sz[row].push_back(s[i]);

                if (row == 0) down = true;
                else if (row == numRows - 1) down = false;

                (down) ? ++row : --row;
            }

            // prevent memory leak
            string szstr = sz[0];
            for (int i = 1; i < numRows; ++i)
                szstr += sz[i];

            delete[] sz;

            return szstr;
        }

    }
};

int main(){

    Solution sln;
    printf("%s\n", sln.convert("abcde", 2).c_str());

    return 0;

}