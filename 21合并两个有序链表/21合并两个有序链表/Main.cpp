#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t = new ListNode;
        ListNode* r_L = t;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                t->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                t->val = list2->val;
                list2 = list2->next;
            }
            t->next = new ListNode;
            t = t->next;
        }
        if (list1)
        {
            while (list1->next)
            {
                t->val = list1->val;
                t->next = new ListNode;
                t = t->next;
                list1 = list1->next;
            }
        }
        if (list2)
        {
            while (list2->next)
            {
                t->val = list2->val;
                t->next = new ListNode;
                t = t->next;
                list2 = list2->next;
            }
        }
        if (list1)
        {
            t->val = list1->val;
            t->next = nullptr;
        }
        else
        {
            t->val = list2->val;
            t->next = nullptr;
        }
        return r_L;
    }
};

int main()
{
    ;
}