#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/3sum-closest/
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int result = nums[0] + nums[1] + nums[2];

        // -4 -1 1 2, target = 1
        for (int i = 0; i != nums.size() - 2; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int sum_to_find = target - nums[i];
            int l = i + 1, r = nums.size() - 1;
            int closest_sum = nums[l] + nums[r];
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (abs(sum_to_find - sum) < abs(sum_to_find - closest_sum)) {
                    closest_sum = sum;
                }
                if (sum < sum_to_find) {
                    ++l;
                } else {
                    --r;
                }
            }
            closest_sum += nums[i];
            if (abs(target - closest_sum) < abs(target - result)) {
                result = closest_sum;
            }
        }
        return result;
    }
};

int main() {
    /*
        Input: nums = [-1,2,1,-4], target = 1
        Output: 2
        Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
    */
    auto solution = Solution();
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    cout << solution.threeSumClosest(nums, target) << endl;
    return 0;
}