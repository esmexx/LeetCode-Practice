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

        ListNode* l3 = new ListNode(0);
        int sum;

        while (!s1.empty() || !s2.empty()){
            sum = l3->val;
            if (!s1.empty()) sum += s1.top();
            if (!s2.empty()) sum += s2.top();

            if (sum >= 10){
                l3->val = sum % 10;
                if (!s1.empty()) s1.pop();
                if (!s2.empty()) s2.pop();
                pushNode(l3, 1);
            }
            else {
                l3->val = sum;
                if (!s1.empty()) s1.pop();
                if (!s2.empty()) s2.pop();
                // if there is no more nodes to sum, do not push 0; otherwise will have a leading 0
                if (!s1.empty() || !s2.empty()) pushNode(l3, 0);
            }
        }


        return l3;
    }

};

int main() {

    ListNode* list1 = NULL;
    ListNode* list2 = NULL;
    ListNode* list3 = NULL;

    pushNode(list1, 2);
    pushNode(list1, 6);
    pushNode(list1, 3);

    printList(list1);

    pushNode(list2, 4);
    pushNode(list2, 5);
    pushNode(list2, 2);

    printList(list2);

    Solution sln;
    list3 = sln.addTwoNumbers(list1, list2);

    if (list3) printList(list3);

    return 0;
}