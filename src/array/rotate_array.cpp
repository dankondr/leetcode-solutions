#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/rotate-array/
    void rotate(vector<int> &nums, int k) {
        k %= nums.size();
        swap(nums, 0, nums.size());
        swap(nums, 0, k);
        swap(nums, k, nums.size());
    }

    void swap(vector<int> &nums, int l, int r) {
        while (l + 1 < r) {
            std::swap(nums[l++], nums[r-- - 1]);
        }
    }
};

int main() {
    /*
        Input: nums = [1,2,3,4,5,6,7], k = 3
        Output: [5,6,7,1,2,3,4]
        Explanation:
        rotate 1 steps to the right: [7,1,2,3,4,5,6]
        rotate 2 steps to the right: [6,7,1,2,3,4,5]
        rotate 3 steps to the right: [5,6,7,1,2,3,4]
    */
    auto solution = Solution();
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 8;
    solution.rotate(nums, k);
    for (int i = 0; i != nums.size(); ++i) {
        if (i > 0) { cout << ", "; }
        cout << nums[i];
    }
    return 0;
}