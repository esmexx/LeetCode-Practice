#include <iostream>
#include <string>

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

        // the substring ranges from strl to strr
        int strl = 0, strr = 0;
        int longest_str_len = 0;

        while (strl<s.size() && strr<s.size()){

            if (char2idx[s[strr]] == -1 || char2idx[s[strr]]<strl) {
                // if the char has not been seen or if it is not within the range of current substring
                char2idx[s[strr]] = strr;
            }
            else {
                // if the char has been seen, update the range of the substring
                strl = ++char2idx[s[strr]];
                char2idx[s[strr]] = strr;

            }
            // increase the length of the substring by moving strr to further right
            ++strr;

            int str_len = strr - strl;
            if (str_len > longest_str_len) longest_str_len = str_len;

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

    return 0;
}