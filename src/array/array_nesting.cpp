#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/array-nesting/
    int arrayNesting(vector<int>& nums) {
        int longest_cycle = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == -1) { continue; }
            int cycle_index = nums[i];
            nums[i] = -1;
            int cycle_length = 1;
            while (nums[cycle_index] != -1) {
                int old_index = cycle_index;
                cycle_index = nums[cycle_index];
                nums[old_index] = -1;
                cycle_length++;
            }
            longest_cycle = max(longest_cycle, cycle_length);
        }
        return longest_cycle;
    }
};

int main() {
    /*
        Input: A = [5,4,0,3,1,6,2]
        Output: 4
        Explanation:
        A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
        One of the longest S[K]:
        S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
    */
    auto solution = Solution();
    vector<int> nums = {5,4,0,3,1,6,2};
    auto result = solution.arrayNesting(nums);
    cout << result << endl;
    return 0;
}