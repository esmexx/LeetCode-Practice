
#include <iostream>
using namespace std;

// https://leetcode.com/problems/add-two-numbers/description/
// Definition for singly-linked list
struct ListNode{
    int val;
	ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void pushNode(ListNode*& list, int val){
    ListNode* newNode = new ListNode(val);
    // link the old list to the new node
    newNode->next = list;
    // move the head to point to new node
    list = newNode;
}

void printList(ListNode* list){
    while (list->next){
        cout << list->val << " -> ";
        list = list->next;
    }
    cout << list->val << endl;
}

// https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        ListNode* l3_cur = NULL;

        int sum, res;
        while (l1 || l2){
            // if one list is shorter than the other, then fill in 0
            if (!l1) l1 = new ListNode(0);
            if (!l2) l2 = new ListNode(0);

            sum = l1->val + l2->val;
            res = sum % 10;
            if (sum >= 10){
                if (l1->next) ++l1->next->val;
                else l1->next = new ListNode(1);
            }

            l1 = l1->next;
            l2 = l2->next;

            if (!l3) {
            	l3 = new ListNode(res);
                l3_cur = l3;
        	}
            else {
                l3_cur->next = new ListNode(res);
            	l3_cur = l3_cur->next;
            }
        }

        return l3;
    }
};


int main() {

    ListNode* list1 = NULL;
    ListNode* list2 = NULL;

    // fill in list1
    pushNode(list1, 5);
    pushNode(list1, 2);
    pushNode(list1, 4);
    pushNode(list1, 9);

    cout << "List 1 is ";
    printList(list1);

    // fill in list2
    pushNode(list2, 8);
    pushNode(list2, 2);
    pushNode(list2, 6);
    pushNode(list2, 7);

    cout << "List 2 is ";
    printList(list2);

    Solution sln;
    ListNode* list_sum = sln.addTwoNumbers(list1, list2);

    cout << "The sum is ";
    printList(list_sum);

    return 0;
}