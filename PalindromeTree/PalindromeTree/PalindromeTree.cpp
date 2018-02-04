#include <iostream>
#define MAXN 1000
using namespace std;

// EERTREE: An Ecient Data Structure for Processing Palindromes in Strings
// arXiv:1506.04862
// http://adilet.org/blog/25-09-14/

struct node{
    int len; // length of the palindrome string stored in the node
    int next[26]; // directed edge 
    int sufflink; // suffix link pointing to the largest suffix-palindrome
};


string s; // store the input string
node tree[MAXN]; // the eertree of a string S of length n is of size O(n)

void addLetter(int pos){
    int let = s[pos] - 'a'; // convert char to number



}

void initTree(){
    // node 1: root with len -1, node 2: root with len 0
    tree[1].len = -1;
    tree[1].sufflink = 1;
    tree[2].len = 0;
    tree[2].sufflink = 1;
}

int main(){

    s = "eertree";

    initTree();

    for (int i = 0; i < s.length(); ++i){
        addLetter(i);
    }

    return 0;
}

