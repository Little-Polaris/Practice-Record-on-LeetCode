#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
        {
            return nullptr;
        }
        ListNode* re_node = head->next;
        ListNode* l = head;
        ListNode* former = l;
        ListNode* latter = l->next;
        if (latter)
        {
            former->next = swapPairs(latter->next);
        }
        else
        {
            return former;
        }
        latter->next = former;
        return re_node;
    }
};

int main()
{
    int n;
    cin >> n;
    ListNode* list = new ListNode;
    ListNode* head = list;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> list->val;
        list->next = new ListNode;
        list = list->next;
    }
    cin >> list->val;
    list->next = nullptr;
    head = Solution().swapPairs(head);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}