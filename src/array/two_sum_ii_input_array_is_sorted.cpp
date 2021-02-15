#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            }
            sum < target ? ++i : --j;
        }
        return {};
    }

    string repr(vector<int> answer) {
        return to_string(answer[0]) + " " + to_string(answer[1]);
    }
};

int main() {
    /*
        Input: nums = [2,7,11,15], target = 9
        Output: [1,2]
     */
    auto solution = Solution();
    vector<int> nums = {2,7,11,15};
    int target = 9;
    cout << solution.repr(solution.twoSum(nums, target)) << endl;
    return 0;
}