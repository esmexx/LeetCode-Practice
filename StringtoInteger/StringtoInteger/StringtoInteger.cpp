#include <iostream>
#include <algorithm>
using namespace std;

//https://leetcode.com/problems/string-to-integer-atoi/description/
// requirements:
// 1. discard leading whitespace characters 
// 2. converted only numerical digits after an optional plus or minus sigh
// 3. do no conversion if: (1) the first non-whitespace character is not a valid integral number
//  (2) the string is empty or contains only whitespace characters

class Solution{
public:
    string trimLeadingSpace(string str){
        int p = str.find_first_not_of(" \t");
        str.erase(0, p);
        return str;
    }

    int myAtoi(string str){
        int result = 0;
        bool is_negative = false, check_digit = false;
        str = trimLeadingSpace(str);


        if (str[0] == '\-') {
            is_negative = true;
            check_digit = true;
        }

        if (str[0] == '\+') {
            check_digit = true;
        }

        if (isdigit(str[0])){
            result = result * 10 + (str[0] - '0');
            check_digit = true;
        }

        if (check_digit){
            for (int i = 1; i < str.length(); ++i){
                if (isdigit(str[i])){
                    result = result * 10 + (str[i] - '0');
                    continue;
                }
                break;
            }
        }

        is_negative ? result = -1 * result : result = result;

        return result;
    }
};


int main(){

    string str = "2147483648";
    int result;

    Solution sln;
    result = sln.myAtoi(str);

    cout << result << endl;

    return 0;
}