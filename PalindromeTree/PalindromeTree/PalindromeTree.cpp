#include <iostream>
#define MAXLEN 1000
using namespace std;

// EERTREE: An Ecient Data Structure for Processing Palindromes in Strings
// arXiv:1506.04862

class TreeNode {
public:
    int NodeLen;
    int SuffixLink; // points to the longest proper suffix-palindrome of the node
};

class EERTree {

    TreeNode tree[MAXLEN];

public:
    void InitTree(){
        // node -1
        tree[0].NodeLen = -1;
        tree[0].SuffixLink = 0; // pointing to self
        // node 0
        tree[1].NodeLen = 0;
        tree[1].SuffixLink = 0; // pointing to node -1        
    }

};

int main(){

    return 0;
}