class Solution {
public:
    vector<vector<int>> howSumAll(vector<int>& a, int target, unordered_map<int, vector<vector<int>>>& memo) {
        if (memo.find(target) != memo.end()) return memo[target];
        if (target == 0) return {{}};
        if (target < 0) return {};

        vector<vector<int>> allCombs;

        for (int& num : a) {
            int nextNode = target - num;
            vector<vector<int>> res = howSumAll(a, nextNode, memo);

            if (!res.empty()) {
                for (auto& comb : res) {
                    comb.push_back(num);
                    allCombs.push_back(comb);
                }
            }
        }

        memo[target] = allCombs;
        return allCombs;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<int, vector<vector<int>>> memo;
        set<vector<int>> unique_combinations;
        vector<vector<int>> vec = howSumAll(candidates, target, memo);
        for (auto comb : vec) {
            sort(comb.begin(), comb.end());
            unique_combinations.insert(comb);
        }
        return vector<vector<int>>(unique_combinations.begin(), unique_combinations.end());    }
};