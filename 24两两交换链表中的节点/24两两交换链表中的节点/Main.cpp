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
        ListNode* re_node = head->next;
        ListNode* l = head->next;
        int flag = 1;
        while (l->next && l->next->next)
        {
            if (flag)
            {
                ListNode* former = head;
                ListNode* latter = head->next;
                former->next = latter->next;
                latter->next = former;
                flag = 0;
            }
            else
            {
                ListNode* former = head;
                ListNode* latter = head->next;
                former->next = latter->next;
                latter->next = latter->next->next;
                former->next->next = latter;    
            }
            l = l->next;
        }
        return re_node;
    }
};

int main(int argc, char* argv[])
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