#include <iostream>
using namespace std;

//https://leetcode.com/problems/string-to-integer-atoi/description/
// requirements:
// 1. discard leading whitespace characters 
// 2. converted only numerical digits after an optional plus or minus sigh
// 3. do no conversion if: (1) the first non-whitespace character is not a valid integral number
//  (2) the string is empty or contains only whitespace characters
// 4. If no valid conversion could be performed, a zero value is returned. If the correct value 
//  is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned

class Solution{
public:
    int myAtoi(string str){
        int result = 0, idx = 0;
        bool is_negative = false;

        while (str[idx] == ' ') idx++;

        if (str[idx] == '-' || str[idx] == '+'){
            is_negative = (str[idx] == '-') ? true : false;
            idx++;
        }

        while (str[idx] >= '0' && str[idx] <= '9'){
            if ((result == INT_MAX / 10 && (str[idx] - '0') > INT_MAX % 10) || (result > INT_MAX / 10 && isdigit(str[idx]))){
                is_negative ? result = abs(INT_MIN) : result = INT_MAX;
                break;
            }
            result = result * 10 + (str[idx] - '0');
            idx++;
        }

        result = is_negative ? -1 * result : result;

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