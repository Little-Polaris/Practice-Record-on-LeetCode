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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int flag = 0;
        ListNode* temp = nullptr;
        for (auto i : lists)
        {
            if (i)
            {
                temp = i;
                flag = 1;
            }
        }
        if (!flag)
        {
            return nullptr;
        }
        int min = -1;
        for (auto it = lists.begin(); it != lists.end(); it++)
        {
            if (*it == nullptr)
            {
                continue;
            }
            if ((*it)->val <= temp->val)
            {
                temp = *it;
                min = it - lists.begin();
            }
        }
        ListNode* node = new ListNode;
        node->val = lists[min]->val;
        lists[min] = lists[min]->next;
        node->next = mergeKLists(lists);
        return node;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(3);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        while (t)
        {
            v[i].push_back(t);
            cin >> t;
        }
    }
    vector<ListNode*> lists(n);
    for (int i = 0; i < n; i++)
    {
        lists[i] = new ListNode;
    }
    auto cache = lists;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size() - 1; j++)
        {
            lists[i]->val = v[i][j];
            lists[i]->next = new ListNode;
            lists[i] = lists[i]->next;
        }
        lists[i]->val = v[i][v[i].size() - 1];
        lists[i]->next = nullptr;
    }
    lists = cache;
    auto L = Solution().mergeKLists(lists);
    while (L->next)
    {
        cout << L->val << " ";
        L = L->next;
    }
    cout << L->val << endl;
	return 0;
}