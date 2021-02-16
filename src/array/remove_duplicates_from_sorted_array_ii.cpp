#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int count = 1;
        int same_letter_count = 1;
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[count++] = nums[i];
                same_letter_count = 1;
            } else {
                if (same_letter_count == 1) {
                    nums[count++] = nums[i];
                    ++same_letter_count;
                }
            }
        }
        return count;
    }
};

int main() {
    /*
        Input: nums = [1,1,1,2,2,3]
        Output: 5, nums = [1,1,2,2,3]
    */
    auto solution = Solution();
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int result = solution.removeDuplicates(nums);
    cout << result << endl;
    for (int i = 0; i != nums.size(); ++i) {
        cout << nums[i] << ' ';
        if (i + 1 == result) cout << "  ";
    }
    cout << endl;
    return 0;
}