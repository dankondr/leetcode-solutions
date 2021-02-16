#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/3sum/
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i != nums.size() - 2; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int sum_to_find = 0 - nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == sum_to_find) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l + 1] == nums[l]) {
                        ++l;
                    }
                    while (l < r && nums[r - 1] == nums[r]) {
                        --r;
                    }
                    ++l, --r;
                } else if (sum < sum_to_find) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return result;
    }
};

int main() {
    /*
        Input: nums = [-1,0,1,2,-1,-4]
        Output: [[-1,-1,2],[-1,0,1]]
    */
    auto solution = Solution();
    vector<int> nums = {-1,0,1,2,-1,-4};
    solution.threeSum(nums);
    return 0;
}