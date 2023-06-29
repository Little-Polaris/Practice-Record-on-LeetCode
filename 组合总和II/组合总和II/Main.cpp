#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	vector<int>candidates_count;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		candidates_count.resize(51);
		for (auto i : candidates) {
			candidates_count[i]++;
		}
		set<int>s(candidates.begin(), candidates.end());
		candidates.assign(s.begin(), s.end());
		vector<vector<int>> result;
		dfs(result, candidates, 0, target, target);
		int sum = 0;
		for (auto i : result.back())
		{
			sum += i;
		}
		if (sum != target)
		{
			result.erase(result.end() - 1);
		}
		set<vector<int>> temp(result.begin(), result.end());
		result.assign(temp.begin(), temp.end());
		return result;
	}
	int dfs(vector<vector<int>>& result, vector<int>& candidates, int index, int target, int& original_target) {
		if (target < 0) {
			return 0;
		}
		if (target == 0) {
			return 1;
		}
		if (target == original_target) {
			result.push_back({});
		}
		for (int i = index; i < candidates.size(); i++) {
			if (candidates_count[candidates[i]]) {
				candidates_count[candidates[i]]--;
				result.back().push_back(candidates[i]);
				int rev = dfs(result, candidates, i, target - candidates[i], original_target);
				if (rev == 0) {	
					return 2;
				}
				else if (rev == 1) {
					if (find(result.begin(), result.end(), result.back()) == result.end() - 1) {
						result.push_back(vector<int>(result.back()));
					}
					return 2;
				}
				else if (rev == 2) {
					candidates_count[result.back().back()]++;
					result.back().pop_back();
					candidates_count[result.back().back()]++;
					result.back().pop_back();
				}
				else if (rev == 3) {
					candidates_count[result.back().back()]++;
					result.back().pop_back();
				}
			}
			else if (i < candidates.size() - 1) {
				candidates_count[candidates[i + 1]]--;
				result.back().push_back(candidates[i + 1]);
				int rev = dfs(result, candidates, i + 1, target - candidates[i + 1], original_target);
				if (rev == 0) {
					return 2;
				}
				else if (rev == 1) {
					if (find(result.begin(), result.end(), result.back()) == result.end() - 1) {
						result.push_back(vector<int>(result.back()));
					}
					return 2;
				}
				else if (rev == 2) {
					candidates_count[result.back().back()]++;
					result.back().pop_back();
					candidates_count[result.back().back()]++;
					result.back().pop_back();
				}
				else if (rev == 3) {
					candidates_count[result.back().back()]++;
					result.back().pop_back();
				}
			}
			else {
				return 0;
			}
		}
		return 3;
	}
};

int main()
{
	vector<int> candidates;
	candidates = { 4, 4, 2, 1, 4, 2, 2, 1, 3 };
	candidates = vector<int>(50, 1);
	candidates = { 5, 4, 5, 1, 5, 3, 1, 4, 5, 5, 4 };
	vector<vector<int>> result = Solution().combinationSum2(candidates, 10);
	for (auto i : result) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}