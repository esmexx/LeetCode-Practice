#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, ListNode*& l3){
        // traverse to the tail of the two lists
        if (l1->next || l2->next){
            if (!l1->next) return addTwoNumbers(l1, l2->next, l3);
            if (!l2->next) return addTwoNumbers(l1->next, l2, l3);
            return addTwoNumbers(l1->next, l2->next, l3);
        } 
        
        int sum, res, sum2, res2;
        sum = l1->val + l2->val;
        res = sum % 10;
        
        if (sum >= 10){
            if (!l3) {
                l3 = new ListNode(res);
                pushNode(l3, 1); 
            }
            else {
                sum2 = l3->val + sum;
                // sum2 must be between [10, 27]
                if (sum2 >= 20){
                    res2 = sum2 % 10;
                    l3->val = res2;
                    pushNode(l3, 2);
                }
                else {
                    res2 = sum2 % 10;
                    l3->val = res2;
                    pushNode(l3, 1);
                }
            }
        }
        else {
            if (!l3) l3 = new ListNode(res);
            else {
                sum2 = l3->val + sum;
                // here, sum2 must be between [0, 18]
                if (sum2 >= 10){
                    res2 = sum2 % 10;
                    l3->val = res2;
                    pushNode(l3, 1);
                }
                else{
                    l3->val = sum2;
                }
            }
        }

        return l3;
    }

};

int main() {

    ListNode* list1 = NULL;
    ListNode* list2 = NULL;
    ListNode* list3 = NULL;

    pushNode(list1, 3);
    pushNode(list1, 6);
    pushNode(list1, 5);
    pushNode(list1, 1);

    printList(list1);

    pushNode(list2, 2);
    pushNode(list2, 4);
    pushNode(list2, 8);

    printList(list2);

    Solution sln;
    sln.addTwoNumbers(list1, list2, list3);

    if (list3) printList(list3);

    return 0;
}