#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/merge-intervals/
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[0] < b[0];
             });
        vector<vector<int>> result;
        int l = intervals[0][0];
        int r = intervals[0][1];
        for (int i = 1; i != intervals.size(); ++i) {
            if (r >= intervals[i][0]) {
                r = max(r, intervals[i][1]);
                l = min(l, intervals[i][0]);
            } else {
                result.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        result.push_back({l, r});
        return result;
    }
};

int main() {
    /*
        Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
        Output: [[1,6],[8,10],[15,18]]
        Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
    */
    auto solution = Solution();
    vector<vector<int>> nums = {{1, 4}, {4, 5}};
    auto result = solution.merge(nums);
    cout << "[";
    for (int i = 0; i != result.size(); ++i) {
        if (i > 0) { cout << "],"; }
        cout << "[";
        for (int j = 0; j != result[i].size(); ++j) {
            if (j > 0) { cout << ", "; }
            cout << result[i][j];
        }
    }
    cout << "]]" << endl;
    return 0;
}