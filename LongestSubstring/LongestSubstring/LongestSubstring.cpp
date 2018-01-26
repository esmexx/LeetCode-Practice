#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// https://leetcode.com/articles/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // len=128 for ASCII, len=256 for Extended ASCII
        int len = 128;
        int* char2idx = new int[len];
        for (int i = 0; i<len; ++i)
            char2idx[i] = -1;

        int longest_str_len = 0;

        for (int strl = 0, strr = 0; strr < s.size();) {

            strl = max(strl, ++char2idx[s[strr]]);
            char2idx[s[strr]] = strr;
            ++strr;

            longest_str_len = max(strr-strl, longest_str_len);

        }

        delete[] char2idx;
        return longest_str_len;
    }
};

int main(){

    Solution sln;
    cout << sln.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << sln.lengthOfLongestSubstring("bbbbb") << endl;
    cout << sln.lengthOfLongestSubstring("pwwkew") << endl;
    cout << sln.lengthOfLongestSubstring("c") << endl;

    return 0;
}