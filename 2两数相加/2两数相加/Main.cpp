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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* List = new ListNode;
        ListNode* head = List;
        ListNode* pre{};
        int c = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            int temp = l1->val + l2->val + c;
            c = temp / 10;
            List->val = temp % 10;
            List->next = new ListNode;
            pre = List;
            List = List->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            int temp = l1->val + c;
            c = temp / 10;
            List->val = temp % 10;
            List->next = new ListNode;
            pre = List;
            List = List->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            int temp = l2->val + c;
            c = temp / 10;
            List->val = temp % 10;
            List->next = new ListNode;
            pre = List;
            List = List->next;
            l2 = l2->next;
        }
        if (c)
        {
            List->val = c;
            pre = List;
        }
        pre->next = nullptr;
        return head;
    }
};

int main()
{
    int m, n;
        cin >> m >> n;
    ListNode* L1 = new ListNode;
    auto head1 = L1;
    ListNode* L2 = new ListNode;
    auto head2 = L2;
    for (int i = 0; i < m; i++)
    {
        cin >> L1->val;
        if (i != m - 1)
        {
            L1->next = new ListNode;
            L1 = L1->next;
        }
        else
        {
            L1->next = nullptr;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> L2->val;
        if (i != n - 1)
        {
            L2->next = new ListNode;
            L2 = L2->next;
        }
        else
        {
            L2->next = nullptr;
        }
    }
    ListNode* ans = Solution().addTwoNumbers(head1, head2);
    return 0;
}