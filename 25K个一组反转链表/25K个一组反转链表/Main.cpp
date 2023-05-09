#include <iostream>
#include <vector>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* list = head;
        for (int i = 0; i < k - 1 && list; i++)
        {
            list = list->next;
        }
        if (!list)
        {
            return head;
        }
        ListNode* re_node = list;
        vector<ListNode*> v;
        for (int i = 0; i < k; i++)
        {
            v.push_back(head);
            head = head->next;
        }
        for (int i = 0; i < k - 1; i++)
        {
            v[i + 1]->next = v[i];
        }
        v[0]->next = reverseKGroup(head, k);
        return re_node;
    }
};


int main()
{
    ListNode* list = new ListNode;
    ListNode* head = list;
    ListNode* last = list;
    int n = 0;
    int flag = 1;
    cin >> n;
    while (n)
    {
        list->val = n;
        list->next = new ListNode;
        last = list;
        list = list->next;
        cin >> n;
    }
    last->next = nullptr;
    list = Solution().reverseKGroup(head, 4);
    while (list)
    {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
	return 0;
}