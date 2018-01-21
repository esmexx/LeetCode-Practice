#include <iostream>
#include <stack>
using namespace std;

// https://www.geeksforgeeks.org/sum-of-two-linked-lists/
// Definition for singly-linked list 
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


void pushNode(ListNode*& ListHead, int val){
    ListNode* newNode = new ListNode(val);
    // link the old list to the new node
    newNode->next = ListHead;
    // move the head to point to new node
    ListHead = newNode;
}

void printList(ListNode* list){
    while (list->next){
        cout << list->val << " -> ";
        list = list->next;
    }
    cout << list->val << endl;
}

// https://www.geeksforgeeks.org/sum-of-two-linked-lists/
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        // use stack to store the list nodes
        stack<int> s1;
        stack<int> s2;
        while (l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2){
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* l3 = NULL;

        while (!s1.empty() || !s2.empty()){
            // fill in zero if one list is shorter than the other
            if (s1.empty()) s1.push(0);
            if (s2.empty()) s2.push(0);
           
            int sum, res, sum2, res2;
            sum = s1.top() + s2.top();
            res = sum % 10;

            if (!l3){
                l3 = new ListNode(res);
                if (sum >= 10) pushNode(l3, 1);
                else pushNode(l3, 0);
            }
            else{
                sum2 = l3->val + sum;
                res2 = sum2 % 10;
                l3->val = res2;
                if (sum2 >= 10) pushNode(l3, 1);
                else pushNode(l3, 0);
            }

            s1.pop(); 
            s2.pop();
        }

        // delete leading zeros
        while (!l3->val) l3 = l3->next;

        return l3;
    }

};

int main() {

    ListNode* list1 = NULL;
    ListNode* list2 = NULL;
    ListNode* list3 = NULL;

    pushNode(list1, 2);
    pushNode(list1, 8);
    pushNode(list1, 5);
    pushNode(list1, 2);

    printList(list1);

    pushNode(list2, 3);
    pushNode(list2, 7);
    pushNode(list2, 4);
    pushNode(list2, 2);

    printList(list2);

    Solution sln;
    list3 = sln.addTwoNumbers(list1, list2);

    if (list3) printList(list3);

    return 0;
}