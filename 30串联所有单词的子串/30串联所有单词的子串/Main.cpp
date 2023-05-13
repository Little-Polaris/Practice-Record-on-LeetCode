#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        /*words = myfunc(words);
        vector<int> r_v;
        for (auto i : words)
        {
            int pos = s.find(i);
            while (pos != -1)
            {
                r_v.push_back(pos);
                pos = s.find(i, pos + 1);
            }
        }
        set<int> ts;
        for (auto i : r_v)
        {
            ts.insert(i);
        }
        copy(ts.begin(), ts.end(), r_v.begin());
        r_v.resize(ts.size());
        return r_v;*/
        if (s.empty())
        {
            return vector<int>();
        }
        int len = s.length();
        int w_l = words[0].length();
        int v_s = words.size();
        vector<int> r_v;
        for (int i = 0; i <= len - w_l * v_s; i++)
        {
            string ts = s.substr(i, w_l * v_s);
            int flag = 1;
            unordered_map<string, int> m;
            for (auto i : words)
            {
                m[i] = 0;
            }
            for (auto i : words)
            {
                m[i]++;
            }
            for (int j = 0; j < ts.size(); j += w_l)
            {  
                string word = ts.substr(j, w_l);
                try
                {
                    m.at(word);
                    m[word]--;
                    if (m[word] < 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                catch(out_of_range)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                r_v.push_back(i);
            }
        }
        return r_v;
    }

    /*vector<string> myfunc(vector<string> words)
    {
        if (words.size() == 1)
        {
            return { words[0] };
        }
        vector<string> r_v;
        for (auto it = words.begin(); it != words.end(); it++)
        {
            auto temp = words;
            temp.erase(temp.begin() + (it - words.begin()));
            auto v1 = myfunc(temp);
            for (auto k : v1)
            {
                r_v.push_back(string(*it + k));
            }
        }
        return r_v;
    }*/
};

int main()
{
    vector<string> v = { "foo","bar" };
    string s = "barfoothefoobarman";
    cout << v.size() << endl;
    auto v1 = Solution().findSubstring(s, v);
    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl << v1.size() << endl;
	return 0;
}