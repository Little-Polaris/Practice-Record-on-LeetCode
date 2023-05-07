#include <iostream>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr && n == 1)
        {
            return nullptr;
        }
        ListNode* l = head;
        ListNode* d = head;
        int count = 0;
        for (int i = 0; i != n; i++)
        {
            l = l->next;
            count++;
        }
        if (l)
        {
            count++;
            l = l->next;
        }
        while (l)
        {
            count++;
            l = l->next;
            d = d->next;
        }
        if (n == count)
        {
            head = head->next;
            delete d;
            return head;
        }
        ListNode* t = d->next;
        d->next = d->next->next;
        delete t;
        return head;
    }
};

int main()
{
    ;
}