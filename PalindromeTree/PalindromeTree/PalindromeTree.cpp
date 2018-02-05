#include <iostream>
#include <map>
#define MAXN 1002
using namespace std;

// EERTREE: An Ecient Data Structure for Processing Palindromes in Strings
// arXiv:1506.04862
// http://adilet.org/blog/25-09-14/

struct node{
    string substr; // substring represented by the node
    int len; // length of the palindrome string stored in the node
    int sufflink; // suffix link pointing to the largest suffix-palindrome
    map<char, int> next; // directed edge
};

int maxlen = 0; // length of the longest palindromic substring
int num; // tree node counter
int suff; // max suffix-palindrome
string s; // the input string
string maxsubstr; // the longest palindromic substring
node tree[MAXN]; // the eertree of a string S of length n is of size O(n)

bool addLetter(int pos){
    int let = s[pos] - 'a'; // convert char to number
    
    int cur = suff, curlen = 0;

    while (true){
        curlen = tree[cur].len; 
        // read palindrome length (curlen) and compare T[i-k] against a (s[pos])
        if (pos - curlen - 1 >= 0 && s[pos - curlen - 1] == s[pos]) break;  // note that pos-curlen-1 = pos when curlen is -1
        cur = tree[cur].sufflink; // move up the suffix links to find substring Q in aQa
    }

    // check whether Q has an outgoing edge labeled by a
    map<char, int>::const_iterator ilet = tree[cur].next.find(s[pos]);
    if (ilet != tree[cur].next.end()){
        suff = ilet->second;
        return false;
    }
    else {
        ++num;
        suff = num; // max suffix-palindrome is now the new node
        tree[num].len = tree[cur].len + 2;
        tree[cur].next.insert(pair<char, int>(s[pos], num));

        if (tree[num].len == 1){ // suffix-palindrome pf node of len 1 is root with len 0
            tree[num].sufflink = 2;
            tree[num].substr = s[pos];
        }
        else {
            tree[num].substr = s[pos] + tree[cur].substr + s[pos];

            while (true){
                cur = tree[cur].sufflink;
                curlen = tree[cur].len;
                if (pos - curlen - 1 >= 0 && s[pos - curlen - 1] == s[pos]) break;
            }

            ilet = tree[cur].next.find(s[pos]);
            tree[num].sufflink = ilet->second;
        }

        if (tree[num].len > maxlen) {
            maxlen = tree[num].len;
            maxsubstr = tree[num].substr;
        }
        return true;
    }
}

void initTree(){
    // node 1: root with len -1, node 2: root with len 0
    tree[1].len = -1;
    tree[1].sufflink = 1;
    tree[2].len = 0;
    tree[2].sufflink = 1;
    // update other parameters
    suff = 2; num = 2;
}

int main(){

    //s = "eertree";
    s = "babad";
    // s = "cbbd";
    initTree();

    for (int i = 0; i < s.length(); ++i){
        addLetter(i);
    }

    printf("%s\n", maxsubstr.c_str());
    return 0;
}

