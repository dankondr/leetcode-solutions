#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen_numbers;
        for (int i = 0; i != nums.size(); ++i) {
            int left = target - nums[i];
            if (seen_numbers.find(left) != seen_numbers.end()) {
                return {seen_numbers[left], i};
            }
            seen_numbers[nums[i]] = i;
        }
        return {};
//        throw Exception("No numbers which sum are target");
    }

    string repr(vector<int> answer) {
        return to_string(answer[0]) + " " + to_string(answer[1]);
    }
};

int main() {
    /*
        Input: nums = [2,7,11,15], target = 9
        Output: [0,1]
        Output: Because nums[0] + nums[1] == 9, we return [0, 1].
     */
    auto solution = Solution();
    vector<int> nums = {2,7,11,15};
    int target = 9;
    cout << solution.repr(solution.twoSum(nums, target)) << endl;
    return 0;
}